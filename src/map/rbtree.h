/*!
\file
\brief Заголовочный файл rbtree.h с реализацией черно-красного дерева для
контейнера map

Данный файл содержит в себе определения классов и методов дерева, его
итераторов
*/

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <limits>

namespace containers {

template <typename Key, typename T, bool IsConst>
class TreeCommonIterator;

/*! Перечисление для значений цвета узла дерева */
enum color_t { red, black };

/*! Определение шаблонного класса узла дерева. Первый параметр - тип ключа,
второй параметр - тип данных */
template <typename Key, typename T>
class Node {
 public:
  using value_type = std::pair<const Key, T>;
  value_type *data_; //< данные узла
  color_t color_; //< цвет узла
  Node *parent_; //< родитель узла
  Node *left_; //< левый ребёнок узла
  Node *right_; //< правый ребёнок узла
  /*!
  Параметризованный конструктор
  */
  Node(value_type *data, color_t color, Node *parent, Node *left, Node *right)
      : data_(data),
        color_(color),
        parent_(parent),
        left_(left),
        right_(right) {}
};

/*! Определение шаблоного класса дерева. Первый параметр - тип ключа, второй -
тип данных, третий - compare (cравнивает значение строкового объекта), четвертый параметр - Allocator по умолчанию,
который используется всеми контейнерами стандартной библиотеки, если не указан
пользовательский Allocator */

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<T>>
class Tree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using NodeAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<Node<key_type, mapped_type>>;
  using DataAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<std::pair<const Key, T>>;
  using iterator = TreeCommonIterator<key_type, mapped_type, false>;
  using const_iterator = TreeCommonIterator<key_type, mapped_type, true>;
  using size_type = size_t;

  friend class Node<Key, T>;
  /*! Конструктор по умолчанию, создает пустое дерево */
  Tree()
      : alloc_(),
        alloc_node_(),
        compare_(),
        root_(nullptr),
        min_node_(nullptr),
        max_node_(nullptr),
        fake_node_(nullptr),
        size_(0){};
  /*! Конструктор списка инициализаторов. Создает дерево, инициализированное с
 * использованием std::initializer_list
 \param[in] items Список для инициализации дерева */

  Tree(std::initializer_list<value_type> const &items)
      : alloc_(),
        alloc_node_(),
        compare_(),
        root_(nullptr),
        min_node_(nullptr),
        max_node_(nullptr),
        fake_node_(nullptr),
        size_(0) {
    for (auto i = items.begin(); i < items.end(); ++i) {
      insert(*i);
    }
  };
  /*! Конструктор копирования
  \param[in] m  дерево для использования в качестве источника данных для
  копирования */
  Tree(const Tree &m)
      : alloc_(),
        alloc_node_(),
        compare_(),
        root_(nullptr),
        min_node_(nullptr),
        max_node_(nullptr),
        fake_node_(nullptr),
        size_(0) {
    CopyElementsForTree(m);
  };
  /*! Конструктор перемещения
  \param[in] m дерево для использования в качестве источника данных для
  перемещения
  */
  Tree(Tree &&m) : alloc_(), alloc_node_(), compare_() {
    MoveTree(std::move(m));
  };

  /*! Оператор присваивания - копирования. Заменяет содержимое дерево копией
  содержимого другого дерева \param[in] m дерево для использования в качестве
  источника данных \return *this
  */
  Tree &operator=(const Tree &m) {
    if (this != &m) {
      clear();
      Tree<key_type, mapped_type> new_tree(m);
      swap(new_tree);
    }
    return *this;
  };

  /*! Оператор присваивания - перемещения. Заменяет содержимое дерево на
  содержимое другого дерева, используя семантику перемещения \param[in] m
  дерево для использования в качестве источника данных \return *this
  */
  Tree &operator=(Tree &&m) {
    if (this != &m) {
      clear();
      Tree new_tree(std::move(m));
      swap(new_tree);
    }
    return *this;
  };
  /*! Деструктор */
  ~Tree() {
    if (!empty()) {
      if (fake_node_ != nullptr) {
        DeleteFakeNode();
      }
      DeallocateDestroyTree(root_);
    }
  };
  /*! Метод accessor для получения корня дерева \return корень дерева
   */
  Node<key_type, mapped_type> *GetRoot() const noexcept { return root_; };
  /*! Метод accessor для получения максимального элемента дерева \return
   * максимальный элемент дерева
   */
  Node<key_type, mapped_type> *GetMax() const noexcept { return max_node_; }
  /*! Метод accessor для получения минимального элемента дерева \return
   * минимальный элемент дерева
   */
  Node<key_type, mapped_type> *GetMin() const noexcept { return min_node_; }
  /*! Метод accessor для получения fake node \return fake node
   */
  Node<key_type, mapped_type> *GetFakeNode() const noexcept {
    return fake_node_;
  }
  /*
  Возвращает ссылку на элемент tree в указанной позиции pos с проверкой
  границ \param[in] key - ключ элемента, который нужно найти \return cсылка на
  сопоставленное значение запрошенного элемента
  */
  mapped_type &at(const key_type &key) const {
    Node<key_type, mapped_type> *ptr = Search(root_, key);
    if (ptr == nullptr) {
      throw std::out_of_range("error");
    }
    return ptr->data_->second;
  };
  /*
  Возвращает ссылку на элемент дерева в указанной позиции pos
  \param[in] key - ключ элемента, который нужно найти \return cсылка на
  сопоставленное значение запрошенного элемента
  */
  mapped_type &operator[](const key_type &key) {
    Node<key_type, mapped_type> *ptr = Search(root_, key);
    if (ptr == nullptr || !CheckFakeNode(ptr)) {
      insert(std::make_pair(key, mapped_type()));
      Node<key_type, mapped_type> *ptr = Search(root_, key);
      return ptr->data_->second;
    }
    return ptr->data_->second;
  };
  /*
  Возвращает ссылку на первый элемент в дереве
  \return Ссылка на первый элемент
  */
  iterator begin() noexcept { return iterator(this, min_node_); };
  /*
  Возвращает ссылку на последний элемент в дереве
  \return Ссылка на последний элемент
  */
  iterator end() noexcept { return iterator(this, fake_node_); }
  /*
  Возвращает сonst-итератор начала дерева
  \return Const-итератор первого элемента
  */
  const_iterator cbegin() const noexcept {
    return const_iterator(this, min_node_);
  };
  /*! Возвращает сonst-итератор конца дерева
  \return Const-итератор конца вектора
  */
  const_iterator cend() const noexcept {
    return const_iterator(this, fake_node_);
  };
  /*! Проверяет есть ли в дереве элементы
  \return Пуст или не пуст контейнер
  */
  bool empty() const noexcept {
    if ((root_ == nullptr)) {
      return true;
    }
    return false;
  };
  /*! Возвращает количество элементов в дереве
  \return Количество элементов в контейнере
  */
  size_type size() const noexcept { return size_; };
  /*! Возвращает максимальное количество элементов, которое дерево может
  хранить из-за ограничений реализации системы или библиотеки \return
  Максимальное количество элементов
  */
  size_type max_size() const noexcept {
    return std::allocator_traits<NodeAlloc>::max_size(alloc_node_);
  };
  /*! Удаление всех элементов из дерева */
  void clear() {
    if (fake_node_ != nullptr) {
      DeleteFakeNode();
    }
    DeallocateDestroyTree(root_);
    root_ = nullptr;
    min_node_ = nullptr;
    max_node_ = nullptr;
    size_ = 0;
  };
  /*! Осущесталяет вставку элемента в дерево
   \param[in] value значение элемента для вставки
   \return Возвращает пару, состоящую из итератора вставленного элемента (или
   элемента, который предотвратил вставку) и логического значения, равного true,
  когда вставка имела место
  */
  std::pair<iterator, bool> insert(const value_type &value) {
    size_++;
    bool result = true;
    auto iter = begin();
    if (empty()) {
      root_ = AllocateNode(root_, value);
      min_node_ = root_;
      max_node_ = root_;
      CreateFakeNode();
      iter = begin();
    } else {
      Node<key_type, mapped_type> *child_node = InsertNotEmpty(value);
      CheckTreeConditions(child_node);
      UpdateParameter();
      iter = begin();
      iter = SearchIterator(child_node->data_->first);
    }
    if (iter == end()) {
      result = false;
      iter = end();
    }
    return std::make_pair(iter, result);
  };
  /*! Осущесталяет вставку элемента в дерево
   \param[in] key значение ключа для вставки
   \param[in] obj значение элемента для вставки
   \return Возвращает пару, состоящую из итератора вставленного элемента (или
   элемента, который предотвратил вставку) и логического значения, равного true, когда вставка имела место
  */
  std::pair<iterator, bool> insert(const key_type &key,
                                   const mapped_type &obj) {
    auto pair = insert(std::make_pair(key, obj));
    return pair;
  };
  /*! Если ключ не существует в дереве, вставляет новое значение, если нет, то
   находит существующий элемент \param[in] key значение ключа для вставки
   \param[in] obj значение элемента для вставки \return Возвращает пару,
   состоящую из итератора вставленного элемента (или элемента, который
   предотвратил вставку) и логического значения, равного true, когда вставка имела место
  */
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj) {
    Node<key_type, mapped_type> *ptr = Search(root_, key);
    bool result = false;
    if (ptr == nullptr || !CheckFakeNode(ptr)) {
      insert(std::make_pair(key, obj));
      result = true;
    }
    auto iter = SearchIterator(key);
    return std::make_pair(iter, result);
  };
  /*! Удаляет указанный элемент из дерева
 \param[in] pos итератор элемента, который нужно удалить
 */
  void erase(iterator pos) {
    Node<key_type, mapped_type> *ptr = Search(root_, (*pos).first);
    if (ptr == nullptr) {
      return;
    }
    auto color = ptr->color_;
    Node<key_type, mapped_type> *child;
    Node<key_type, mapped_type> *parent;
    Node<key_type, mapped_type> *min;
    if (ptr == root_ && size_ == 1) {
      --size_;
      return;
    } else if (ptr->left_ == nullptr) {
      child = ptr->right_;
      parent = ptr->parent_;
      Transplant(ptr, child);
    } else if (ptr->right_ == nullptr) {
      child = ptr->left_;
      parent = ptr->parent_;
      Transplant(ptr, child);
    } else {
      min = MinNode(ptr->right_);
      color = min->color_;
      child = min->right_;
      if (min->parent_ == ptr) {
        parent = min;
      } else {
        Transplant(min, min->right_);
        min->right_ = ptr->right_;
        min->right_->parent_ = min;
        parent = min->parent_;
      }
      Transplant(ptr, min);
      min->left_ = ptr->left_;
      min->left_->parent_ = min;
      min->color_ = ptr->color_;
    }
    DeallocateDestroyNode(ptr);
    if (color == black) {
      CheckTreeAfterDelete(child, parent);
    }
    UpdateParameter();
    --size_;
    if (fake_node_ != nullptr) {
      fake_node_->color_ = black;
    }
  };
  /*! Заменяет содержимое дерева другим
 \param[in] other дерево для обмена содержимым
 */
  void swap(Tree &other) {
    std::swap(alloc_, other.alloc_);
    std::swap(alloc_node_, other.alloc_node_);
    std::swap(compare_, other.compare_);
    std::swap(root_, other.root_);
    std::swap(min_node_, other.min_node_);
    std::swap(max_node_, other.max_node_);
    std::swap(fake_node_, other.fake_node_);
    std::swap(size_, other.size_);
  }
  /*! Соединение деревьев
 \param[in] other совместимое для дерева другое дерево для слияния
 */
  void merge(Tree &other) {
    if (!(other.empty()) && this != &other) {
      for (auto iter = other.begin(); iter != other.end(); ++iter) {
        insert((*iter).first, (*iter).second);
      }
      other.clear();
    }
  };
  /*!
  Проверяет, есть ли в дереве элемент с ключом, эквивалентный требуемому
  \param[in] key - значение ключа
  \return существует или нет элемент с требуемым ключом в контейнере
  */
  bool contains(const Key &key) const {
    Node<key_type, mapped_type> *ptr = Search(root_, key);
    if (ptr == nullptr) {
      return false;
    }
    return true;
  }
  /*! Копирование из одного дерева в другой
  \param[in] m  дерево для использования в качестве источника данных для
  копирования */
  void CopyElementsForTree(const Tree &m) {
    auto it = m.cbegin();
    for (size_t i = 0; i < m.size_; ++i) {
      if (it == m.cend()) {
        break;
      }
      insert(*it);
      it++;
    }
  }
  /*! Перемещение из одного дерева в другой
  \param[in] m дерево для использования в качестве источника данных для
  перемещения
  */
  void MoveTree(Tree &&m) {
    root_ = m.root_;
    min_node_ = m.min_node_;
    max_node_ = m.max_node_;
    fake_node_ = m.fake_node_;
    size_ = m.size_;
    m.root_ = nullptr;
    m.min_node_ = nullptr;
    m.max_node_ = nullptr;
    m.size_ = 0;
  }
  /*! Нахождение минимального элемента в дереве
  \param[out] ptr указатель на элемент дерева
  \return указатель на элемент дерева
  */
  Node<key_type, mapped_type> *MinNode(Node<key_type, mapped_type> *ptr) const {
    if (ptr->left_ == nullptr || !CheckFakeNode(ptr->left_)) {
      return ptr;
    }
    return MinNode(ptr->left_);
  }
  /*! Нахождение максимального элемента в дереве
  \param[out] ptr указатель на узел дерева
  \return указатель на узел дерева
  */
  Node<key_type, mapped_type> *MaxNode(Node<key_type, mapped_type> *ptr) const {
    if (ptr->right_ == nullptr || (!CheckFakeNode(ptr->right_))) {
      return ptr;
    }
    return MaxNode(ptr->right_);
  }
  /*! Проверка элемента узла на fake node
  \param[out] ptr указатель на узел дерева
  \return результат проверки на fake node
  */
  bool CheckFakeNode(Node<key_type, mapped_type> *ptr) const {
    if (ptr != fake_node_) {
      return true;
    }
    return false;
  }

 private:
  DataAlloc alloc_;
  NodeAlloc alloc_node_;
  Compare compare_;
  Node<key_type, mapped_type> *root_;  //< указатель на корень дерева
  Node<key_type, mapped_type> *min_node_;  //< указатель на минимальный элемент
  Node<key_type, mapped_type> *max_node_;  //< указатель на максимальный элемент
  Node<key_type, mapped_type> *fake_node_;  //< указатель на узел fake node
  size_t size_;                             //< размер дерева

  /*! Поиск элемента
  \param[out] ptr указатель на узел дерева
  \param[in] key значение ключа для поиска
  \return указатель на найденный узел дерева
  */
  Node<key_type, mapped_type> *Search(Node<key_type, mapped_type> *ptr,
                                      key_type key) const {
    if (!CheckFakeNode(ptr)) {
      return nullptr;
    }
    if (ptr == nullptr || key == ptr->data_->first) {
      return ptr;
    }
    if (std::less<Key>{}(key, ptr->data_->first)) {
      return Search(ptr->left_, key);
    } else {
      return Search(ptr->right_, key);
    }
  }
  /*! Поиск элемента
  \param[in] key значение ключа для поиска
  \return итератор на найденный узел дерева
  */
  iterator SearchIterator(key_type key) {
    auto iter = begin();
    for (size_t i = 0; i < size_; ++i) {
      if (iter == end()) {
        break;
      }
      if ((*iter).first == key) {
        return iter;
      }
      ++iter;
    }
    return iter;
  }
  /*!
  Выделение памяти для данных дерева
  \param[out] ptr указатель на узел дерева
  \param[in] key значение ключа для узла
  \return указатель на узел дерева
  */
  Node<key_type, mapped_type> *AllocateNode(Node<key_type, mapped_type> *ptr,
                                            const value_type &value) {
    ptr = std::allocator_traits<NodeAlloc>::allocate(alloc_node_, 1);
    try {
      ptr->data_ = std::allocator_traits<DataAlloc>::allocate(alloc_, 1);
      std::allocator_traits<NodeAlloc>::construct(
          alloc_node_, std::addressof(ptr->color_), black);
      std::allocator_traits<DataAlloc>::construct(
          alloc_, std::addressof(ptr->data_->first),
          std::move_if_noexcept(value.first));
      std::allocator_traits<DataAlloc>::construct(
          alloc_, std::addressof(ptr->data_->second),
          std::move_if_noexcept(value.second));
      std::allocator_traits<NodeAlloc>::construct(
          alloc_node_, std::addressof(ptr->right_), nullptr);
      std::allocator_traits<NodeAlloc>::construct(
          alloc_node_, std::addressof(ptr->left_), nullptr);
      std::allocator_traits<NodeAlloc>::construct(
          alloc_node_, std::addressof(ptr->parent_), nullptr);
    } catch (...) {
      std::allocator_traits<NodeAlloc>::deallocate(alloc_node_, ptr, 1);
      throw;
    }
    return ptr;
  }
  /*!
  Очищение памяти под дерево
  \param[out] ptr указатель на узел дерева
  */
  void DeallocateDestroyTree(Node<key_type, mapped_type> *ptr) {
    if (ptr == nullptr || !CheckFakeNode(ptr)) {
      return;
    }
    if (ptr->left_ != nullptr) {
      DeallocateDestroyTree(ptr->left_);
    }

    if (ptr->right_ != nullptr) {
      DeallocateDestroyTree(ptr->right_);
    }
    DeallocateDestroyNode(ptr);
  }
  /*!
  Вспомогательный метод для удаления узла
  \param[out] ptr указатель на узел дерева
  */
  void DeallocateDestroyNode(Node<key_type, mapped_type> *ptr) {
    ptr->right_ = nullptr;
    ptr->left_ = nullptr;
    ptr->parent_ = nullptr;
    std::allocator_traits<DataAlloc>::destroy(alloc_, ptr->data_);
    std::allocator_traits<DataAlloc>::deallocate(alloc_, ptr->data_, 1);
    std::allocator_traits<NodeAlloc>::destroy(alloc_node_, ptr);
    std::allocator_traits<NodeAlloc>::deallocate(alloc_node_, ptr, 1);
    ptr = nullptr;
  }
  /*!
  Создание и выделение памяти под fake node
  */
  void CreateFakeNode() {
    fake_node_ = AllocateNode(fake_node_, value_type());
    if (max_node_ != nullptr) {
      max_node_->right_ = fake_node_;
    }
  }
  /*!
  Удаление данных fake node
  */
  void DeleteFakeNode() {
    max_node_->right_ = nullptr;
    fake_node_->right_ = nullptr;
    std::allocator_traits<DataAlloc>::destroy(alloc_, fake_node_->data_);
    std::allocator_traits<DataAlloc>::deallocate(alloc_, fake_node_->data_, 1);
    std::allocator_traits<NodeAlloc>::destroy(alloc_node_, fake_node_);
    std::allocator_traits<NodeAlloc>::deallocate(alloc_node_, fake_node_, 1);
  }
  /*! Вспомогательный метод для добавления элемента в непустое дерево
   \param[in] value значение элемента для вставки
   \return указатель на узел дерева
  */
  Node<key_type, mapped_type> *InsertNotEmpty(const value_type &value) {
    auto last_node = root_;
    Node<key_type, mapped_type> *parent_node = nullptr;
    Node<key_type, mapped_type> *child_node = nullptr;
    child_node = AllocateNode(child_node, value);
    child_node->color_ = red;
    while (last_node != nullptr && CheckFakeNode(last_node)) {
      parent_node = last_node;
      if (std::less<key_type>{}(last_node->data_->first,
                                child_node->data_->first)) {
        last_node = last_node->right_;
      } else {
        last_node = last_node->left_;
      }
    }
    child_node->parent_ = parent_node;
    if (std::less<key_type>{}(parent_node->data_->first,
                              child_node->data_->first)) {
      parent_node->right_ = child_node;
    } else {
      parent_node->left_ = child_node;
    }
    if (!CheckFakeNode(max_node_->right_)) {
      max_node_->right_ = nullptr;
    }
    return child_node;
  }
  /*! Обновление параметров - минимального, максимального узла
   */
  void UpdateParameter() {
    max_node_ = MaxNode(root_);
    min_node_ = MinNode(root_);
    if (max_node_ != nullptr) {
      max_node_->right_ = fake_node_;
      fake_node_->parent_ = max_node_;
    }
    if (min_node_ != nullptr && fake_node_ != nullptr) {
      fake_node_->right_ = min_node_;
    }
  }
  /*! Левый поворот дерева
  \param[out] ptr указатель на узел дерева
  */
  void RotateLeft(Node<key_type, mapped_type> *ptr) {
    Node<key_type, mapped_type> *child = ptr->right_;
    ptr->right_ = child->left_;
    if (child->left_ != nullptr) {
      child->left_->parent_ = ptr;
    }
    child->parent_ = ptr->parent_;
    if (ptr->parent_ == nullptr) {
      root_ = child;
    } else if (ptr == ptr->parent_->left_) {
      ptr->parent_->left_ = child;
    } else {
      ptr->parent_->right_ = child;
    }
    child->left_ = ptr;
    ptr->parent_ = child;
  };
  /*! Правый поворот дерева
  \param[out] ptr указатель на узел дерева
  */
  void RotateRight(Node<key_type, mapped_type> *ptr) {
    Node<key_type, mapped_type> *child = ptr->left_;
    ptr->left_ = child->right_;
    if (child->right_ != nullptr) {
      child->right_->parent_ = ptr;
    }
    child->parent_ = ptr->parent_;
    if (ptr->parent_ == nullptr) {
      root_ = child;
    } else if (ptr == ptr->parent_->right_) {
      ptr->parent_->right_ = child;
    } else {
      ptr->parent_->left_ = child;
    }
    child->right_ = ptr;
    ptr->parent_ = child;
  }
  /*! Проверка условий черно-красного дерева после добавления
  \param[out] ptr указатель на узел дерева
  */
  void CheckTreeConditions(Node<key_type, mapped_type> *ptr) {
    Node<key_type, mapped_type> *uncle;
    Node<key_type, mapped_type> *parent;
    Node<key_type, mapped_type> *grandparent;
    while (ptr->parent_->color_ == red) {
      parent = ptr->parent_;
      grandparent = ptr->parent_->parent_;
      if (parent == grandparent->right_) {
        uncle = ptr->parent_->parent_->left_;
        if (uncle != nullptr && uncle->color_ == red) {
          uncle->color_ = black;
          parent->color_ = black;
          grandparent->color_ = red;
          ptr = grandparent;
        } else {
          if (ptr == parent->left_) {
            ptr = parent;
            RotateRight(ptr);
            parent = ptr->parent_;
            grandparent = ptr->parent_->parent_;
          }
          parent->color_ = black;
          grandparent->color_ = red;
          RotateLeft(grandparent);
        }
      } else {
        uncle = ptr->parent_->parent_->right_;
        if (uncle != nullptr && uncle->color_ == red) {
          uncle->color_ = black;
          parent->color_ = black;
          grandparent->color_ = red;
          ptr = grandparent;
        } else {
          if (ptr == parent->right_) {
            ptr = parent;
            RotateLeft(ptr);
            parent = ptr->parent_;
            grandparent = ptr->parent_->parent_;
          }
          parent->color_ = black;
          grandparent->color_ = red;
          RotateRight(grandparent);
        }
      }
      if (ptr == root_) {
        break;
      }
    }
    root_->color_ = black;
    fake_node_->color_ = black;
  };
  /*! Перестановка узлов местами
  \param[out] ptr указатель на узел дерева
  \param[out] child указатель ребенка узла дерева
  */
  void Transplant(Node<key_type, mapped_type> *ptr,
                  Node<key_type, mapped_type> *child) {
    if (ptr->parent_ == nullptr) {
      root_ = child;
    } else if (ptr == ptr->parent_->left_) {
      ptr->parent_->left_ = child;
    } else {
      ptr->parent_->right_ = child;
    }
    if (child != nullptr) {
      child->parent_ = ptr->parent_;
    }
  }
  /*! Проверка условий черно-красного дерева после удаления
  \param[out] ptr указатель на узел дерева
  \param[out] parent указатель на родительский узел дерева
  */
  void CheckTreeAfterDelete(Node<key_type, mapped_type> *ptr,
                            Node<key_type, mapped_type> *parent) {
    Node<key_type, mapped_type> *brother;
    while (ptr != root_ && (ptr == nullptr || ptr->color_ == black)) {
      if (ptr == parent->left_) {
        brother = parent->right_;
        if (brother->color_ == red) {
          brother->color_ = black;
          parent->color_ = red;
          RotateLeft(parent);
          brother = parent->right_;
          if (brother == nullptr) {
            break;
          }
        }
        if ((brother->left_ == nullptr || brother->left_->color_ == black) &&
            (brother->right_ == nullptr || brother->right_->color_ == black)) {
          brother->color_ = red;
          ptr = parent;
          parent = parent->parent_;
        } else {
          if (brother->right_ == nullptr || brother->right_->color_ == black) {
            brother->left_->color_ = black;
            brother->color_ = red;
            RotateRight(brother);
            brother = parent->right_;
          }
          brother->color_ = parent->color_;
          parent->color_ = black;
          if (brother->right_ != nullptr) {
            brother->right_->color_ = black;
            RotateLeft(parent);
          }
          ptr = root_;
        }
      } else {
        brother = parent->left_;
        if (brother->color_ == red) {
          brother->color_ = black;
          parent->color_ = red;
          RotateRight(parent);
          brother = parent->left_;
          if (brother == nullptr) {
            break;
          }
        }
        if ((brother->right_ == nullptr || brother->right_->color_ == black) &&
            (brother->left_ == nullptr || brother->left_->color_ == black)) {
          brother->color_ = red;
          ptr = parent;
          parent = parent->parent_;
        } else {
          if (brother->left_ == nullptr || brother->left_->color_ == black) {
            brother->right_->color_ = black;
            brother->color_ = red;
            RotateLeft(brother);
            brother = parent->left_;
          }
          brother->color_ = parent->color_;
          parent->color_ = black;
          if (brother->left_ != nullptr) {
            brother->left_->color_ = black;
            RotateRight(parent);
          }
          ptr = root_;
        }
      }
    }
    ptr->color_ = black;
  }
};

/*! Определение шаблоного класса итератора дерева. Первый параметр - тип
данных, второй параметр - значение типа данных bool для опеределения
итератора: const он или нет */
template <typename Key, typename T, bool IsConst>
class TreeCommonIterator {
 public:
  friend class Tree<Key, T>;
  friend class Node<Key, T>;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;

  using node_type = Node<key_type, mapped_type>;
  using reference = node_type &;
  using const_reference = const node_type &;
  using pointer = node_type *;
  using const_pointer = const node_type *;
  using conditional_node_ptr =
      std::conditional_t<IsConst, const_pointer, pointer>;
  using conditional_node_ref =
      std::conditional_t<IsConst, const_reference, reference>;

  using tree_type = Tree<key_type, mapped_type>;
  using tree_reference = tree_type &;
  using const_tree_reference = const tree_type &;
  using tree_pointer = tree_type *;
  using const_tree_pointer = const tree_type *;
  using conditional_tree_ptr =
      std::conditional_t<IsConst, const_tree_pointer, tree_pointer>;
  using conditional_tree_ref =
      std::conditional_t<IsConst, const_tree_reference, tree_reference>;
  /*! Конструктор итератора по умолчанию*/
  TreeCommonIterator() noexcept : tree_(nullptr), node_(nullptr){};
  /*! Параметризованный конструктор
  \param[out] tree указатель на дерево
  */
  TreeCommonIterator(conditional_tree_ptr tree) : tree_(tree), node_(nullptr){};
  /*! Параметризованный конструктор
  \param[out] tree указатель на дерево
  \param[out] node указатель на узел дерева
   */
  TreeCommonIterator(conditional_tree_ptr tree, conditional_node_ptr node)
      : tree_(tree), node_(node){};
  /*! Перегрузка опрератора *
  \return значение данных дерева
  */
  value_type &operator*() const { return *(node_->data_); }
  /*! Перегрузка опрератора ->
  \return значение данных дерева
  */
  value_type operator->() const { return node_->data_; }
  /*! Перегрузка опрератора ++
  \return *this
  */
  TreeCommonIterator &operator++() {
    node_ = NextNode();
    return *this;
  };
  /*! Перегрузка опрератора ++
  \return *this
  */
  TreeCommonIterator &operator++(int) {
    node_ = NextNode();
    return *this;
  };
  /*! Перегрузка опрератора --
  \return *this
  */
  TreeCommonIterator &operator--() {
    node_ = PreviousNode();
    return *this;
  };
  /*! Перегрузка опрератора --
  \return *this
  */
  TreeCommonIterator &operator--(int) {
    node_ = PreviousNode();
    return *this;
  };
  /*! Перегрузка опрератора ==
  \param[in] other другой итератор дерева для сравнения
  \return проверка на равенство узлов
  */
  bool operator==(const TreeCommonIterator &other) {
    return node_ == other.node_;
  };
  /*! Перегрузка опрератора !=
  \param[in] other другой итератор дерева для сравнения
  \return проверка на равенство узлов
  */
  bool operator!=(const TreeCommonIterator &other) {
    return node_->data_->first != other.node_->data_->first;
  };

 private:
  conditional_tree_ptr tree_;  //< указатель на дерево
  conditional_node_ptr node_;  //< указатель на узел дерева

  /*!
  Обход дерева
  \return указатель на узел дерева
  */
  conditional_node_ptr TraversalTree() const {
    if (node_ == tree_->GetFakeNode()) {
      return tree_->GetMax();
    } else if (node_->right_ != nullptr) {
      return tree_->MinNode(node_->right_);
    } else if (node_->parent_ == nullptr) {
      return tree_->GetFakeNode();
    } else if (node_ == node_->parent_->left_) {
      return node_->parent_;
    } else {
      Node<key_type, mapped_type> *x = node_->parent_;
      while (x == node_->parent_->right_) {
        x = x->parent_;
      }
      return x->parent_;
    }
    return node_;
  }
  /*!
  Обратный обход дерева
  \return указатель на узел дерева
  */
  conditional_node_ptr ReverseTraversalTree() const {
    if (tree_->size() == 1) {
      return tree_->GetRoot();
    } else if (node_->left_ != nullptr) {
      return tree_->MaxNode(node_->left_);
    } else if (node_->parent_ != nullptr && node_ == node_->parent_->right_) {
      return node_->parent_;
    }
    if (node_ == tree_->GetMin()) {
      return tree_->GetFakeNode();
    } else {
      Node<key_type, mapped_type> *x = node_->parent_;
      while (node_->parent_ != nullptr && x == node_->parent_->left_) {
        x = x->parent_;
      }
      return x->parent_;
    }
    return node_;
  }
  /*!
  Следующий элемент дерева
  \return указатель на узел дерева
  */
  conditional_node_ptr NextNode() const { return TraversalTree(); }
  /*!
  Предыдущий элемент дерева
  \return указатель на узел дерева
  */
  conditional_node_ptr PreviousNode() const { return ReverseTraversalTree(); }
};
};      // namespace containers
#endif  //_TREE_H_

#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

#include "rbtree.h"

namespace containers {
/*! Определение шаблоного класса map. Первый параметр - тип ключа, второй -
тип данных, третий - compare (cравнивает значение строкового объекта), четвертый параметр - Allocator по умолчанию,
который используется всеми контейнерами стандартной библиотеки, если не указан
пользовательский Allocator */
template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<T>>
class Map : public Tree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using NodeAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<Node<key_type, mapped_type>>;
  using DataAlloc = typename std::allocator_traits<
      Alloc>::template rebind_alloc<std::pair<const Key, T>>;
  using iterator = TreeCommonIterator<key_type, mapped_type, false>;
  using const_iterator = TreeCommonIterator<key_type, mapped_type, true>;
  using size_type = size_t;

  friend class Tree<Key, T>;
  /*! Конструктор по умолчанию, создает пустой контейнер */
  Map() : tree_(){};
  /*! Конструктор списка инициализаторов. Создает контейнер, инициализированный
 с
 * использованием std::initializer_list
 \param[in] items Список для инициализации контейнера */
  Map(std::initializer_list<value_type> const& items) {
    for (auto i = items.begin(); i != items.end(); ++i) {
      tree_.insert(*i);
    }
  };
  /*! Конструктор копирования
  \param[in] m контейнер map для использования в качестве источника данных для
  копирования */
  Map(const Map& m) : Tree<key_type, mapped_type, Compare, Alloc>(m.tree_) {
    tree_.CopyElementsForTree(m.tree_);
  };
  /*! Конструктор перемещения
  \param[in] m контейнера map для использования в качестве источника данных для
  перемещения
  */
  Map(Map&& m) { tree_.MoveTree(std::move(m.tree_)); }
  /*! Оператор присваивания - копирования. Заменяет содержимое контейнера map
  копией содержимого другого контейнера \param[in] m контейнера для
  использования в качестве источника данных \return *this
  */
  Map& operator=(Map&& m) {
    if (this != &m) {
      clear();
      Map new_map(std::move(m.tree_));
      swap(new_map);
    }
    return *this;
  };

  /*! Оператор присваивания - перемещения. Заменяет содержимое контейнера на
  содержимое другого контейнера, используя семантику перемещения \param[in] m
  контейнер map для использования в качестве источника данных \return *this
  */
  Map& operator=(const Map& m) {
    if (this != &m) {
      clear();
      Map new_map(m.tree_);
      swap(new_map);
    }
    return *this;
  };
  /*! Деструктор */
  ~Map(){};
  /*
  Возвращает ссылку на элемент map в указанной позиции pos с проверкой
  границ \param[in] key - ключ элемента, который нужно найти \return cсылка на
  сопоставленное значение запрошенного элемента
  */
  T& at(const Key& key) const {
    try {
      return tree_.at(key);
    } catch (...) {
      throw std::out_of_range("error");
    }
  };
  /*
  Возвращает ссылку на элемент map в указанной позиции pos
  \param[in] key - ключ элемента, который нужно найти \return cсылка на
  сопоставленное значение запрошенного элемента
  */
  T& operator[](const key_type& key) { return tree_[key]; };
  /*Возвращает ссылку на первый элемент в map
  \return Ссылка на первый элемент
  */
  iterator begin() noexcept { return tree_.begin(); };
  /*
  Возвращает ссылку на последний элемент map
  \return Ссылка на последний элемент
  */
  iterator end() noexcept { return tree_.end(); }
  /* Возвращает сonst-итератор начала map
  \return Const-итератор первого элемента
  */
  const_iterator cbegin() const noexcept { return tree_.cbegin(); };
  /*! Возвращает сonst-итератор конца map
  \return Const-итератор конца вектора
  */
  const_iterator cend() const noexcept { return tree_.cend(); };
  /*! Проверяет есть ли в дереве элементы
  \return Пуст или не пуст контейнер
  */
  bool empty() const noexcept { return tree_.empty(); };
  /*! Возвращает количество элементов в map
  \return Количество элементов в контейнере
  */
  size_type size() const noexcept { return tree_.size(); };
  /*! Возвращает максимальное количество элементов, которое map может
  хранить из-за ограничений реализации системы или библиотеки \return
  Максимальное количество элементов
  */
  size_type max_size() const noexcept { return tree_.max_size(); };
  /*! Удаление всех элементов из контейнера */
  void clear() { tree_.clear(); };
  /*! Производит вставку элементов в map
   \param[in] value значение элемента для вставки
   \return Возвращает пару, состоящую из итератора вставленного элемента (или
   элемента, который предотвратил вставку) и логического значения, равного true,
   когда вставка имела место
  */
  std::pair<iterator, bool> insert(const value_type& value) {
    auto iter = tree_.insert(value);
    return iter;
  };
  /*! Производит вставку элемента в map
   \param[in] key значение ключа для вставки
   \param[in] obj значение элемента для вставки
   \return Возвращает пару, состоящую из итератора вставленного элемента (или
   элемента, который предотвратил вставку) и логического значения, равного true, когда вставка имела место
  */
  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    auto iter = tree_.insert(key, obj);
    return iter;
  };
  /*! Если ключ не существует в map, вставляет новое значение, если нет, то
   находит существующий элемент \param[in] key значение ключа для вставки
   \param[in] obj значение элемента для вставки \return Возвращает пару,
   состоящую из итератора вставленного элемента (или элемента, который
   предотвратил вставку) и логического значения, равного true, когда вставка имела место
  */
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
    auto iter = tree_.insert_or_assign(key, obj);
    return iter;
  };
  /*! Удаляет указанный элемент из контейнера map
 \param[in] pos итератор элемента, который нужно удалить
 */
  void erase(iterator pos) { tree_.erase(pos); };
  /*! Заменяет содержимое map другим контейнером map
\param[in] other map для обмена содержимым
*/
  void swap(Map& other) { tree_.swap(other.tree_); };
  /*! Соединение контейнеров map
\param[in] other совместимый c map другой контейнер для слияния
*/
  void merge(Map& other) { tree_.merge(other.tree_); };
  /*!
  Проверяет, есть ли в контейнере map элемент, эквивалентный требуемому ключу
  \param[in] key - ключевое значение элемента для поиска
  \return Существует или нет элемент в контейнере
  */
  bool contains(const Key& key) const { return tree_.contains(key); };

 private:
  Tree<key_type, mapped_type, Compare, Alloc> tree_;  //< объект класса дерева
};

};      // namespace containers
#endif  //_MAP_H_

/*!
\file
\brief Заголовочный файл vector.h с реализацией контейнера vector

Данный файл содержит в себе определения классов и методов вектора, его
итераторов
*/

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <limits>

namespace containers {


template <typename T, bool IsConst>
class CommonIterator;

/*! Определение шаблоного класса вектора. Первый параметр - тип данных,
второй параметр - Allocator по умолчанию, который используется всеми
контейнерами стандартной библиотеки, если не указан пользовательский Allocator */

template <typename T, typename Alloc = std::allocator<T>>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using iterator = CommonIterator<T, false>;
  using const_iterator = CommonIterator<T, true>;
  using size_type = size_t;
  /*! Конструктор по умолчанию, создает пустой вектор */
  Vector() noexcept : alloc(), array_(nullptr), size_(0), capacity_(0){};
  /*! Параметризованный конструктор, создает вектор размера n
  \param[in] count размер вектора n
   */
  explicit Vector(size_t count)
      : alloc(), array_(nullptr), size_(count), capacity_(count) {
    AllocateMemory();
    for (size_type i = 0; i < size_; ++i) {
      ConstructDestroy(i, value_type());
    }
  }
  /*! Конструктор списка инициализаторов. Создает вектор, инициализированный с
 * использованием std::initializer_list
 \param[in] items список для инициализации вектора */
  Vector(std::initializer_list<value_type> const &items)
      : alloc(), array_(nullptr), size_(items.size()), capacity_(items.size()) {
    AllocateMemory();
    iterator it = begin();
    for (auto i = items.begin(); i < items.end(); ++i) {
      std::allocator_traits<Alloc>::construct(alloc, std::addressof(*it), *i);
      ++it;
    }
  };
  /*! Конструктор копирования
  \param[in] v контейнер для использования в качестве источника данных для
  копирования */
  Vector(const Vector &v)
      : alloc(), array_(nullptr), size_(v.size_), capacity_(v.capacity_) {
    AllocateMemory();
    iterator it = begin();
    for (auto i = v.cbegin(); i < v.cend(); ++i) {
      std::allocator_traits<Alloc>::construct(alloc, std::addressof(*it), *i);
      ++it;
    }
  };

  /*! Конструктор перемещения
  \param[in] v контейнер для использования в качестве источника данных для
  перемещения
  */
  Vector(Vector &&v) noexcept
      : array_(v.array_), size_(v.size_), capacity_(v.capacity_) {
    v.array_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  };

  /*! Оператор присваивания - копирования. Заменяет содержимое вектора копией
  содержимого другого вектора \param[in] v Контейнер для использования в
  качестве источника данных \return *this
  */
  Vector &operator=(const Vector &v) {
    if (this != &v) {
      if (v.capacity() < capacity_) {
        for (size_type i = 0; i < size_; ++i) {
          std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
        }
        for (size_type i = 0; i < v.size(); ++i) {
          ConstructDestroy(i, v.at(i));
        }
        size_ = v.size();
      } else {
        clear();
        Vector new_vector(v);
        swap(new_vector);
      }
    }
    return *this;
  };

  /*! Оператор присваивания - перемещения. Заменяет содержимое вектора на
  содержимое другого контейнера, используя семантику перемещения. \param[in] v
  контейнер для использования в качестве источника данных \return *this
  */
  Vector &operator=(Vector &&v) noexcept {
    if (this != &v) {
      clear();
      Vector new_vector(std::move(v));
      swap(new_vector);
    }
    return *this;
  };
  /*! Деструктор */
  ~Vector() {
    DeleteMemory();
    size_ = 0;
    capacity_ = 0;
    array_ = nullptr;
  };
  /*
  Возвращает ссылку на элемент вектора в указанной позиции pos с проверкой
  границ \param[in] pos - позиция возвращаемого элемента \return Ссылка на
  запрошенный элемент
  */
  reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range("error");
    } else {
      return array_[pos];
    }
  };
  /*
  Возвращает ссылку на элемент вектора в указанной позиции pos
  \param[in] pos - позиция возвращаемого элемента
  \return Ссылка на запрошенный элемент
  */
  reference operator[](size_type pos) {
    if (pos > size_) {
      throw std::out_of_range("error");
    }
    return array_[pos];
  };
  /*
  Возвращает ссылку на первый элемент в контейнере
  \return Ссылка на первый элемент
  */
  const_reference front() const { return *(array_); };
  /*
  Возвращает ссылку на последний элемент в контейнере
  \return Ссылка на последний элемент
  */
  const_reference back() const { return *(array_ + size_ - 1); };
  /*
  Возвращает указатель на значение базового элемента из хранилища элементов
  \return Указатель на значение базового элемента
  */
  pointer data() noexcept {
    if (array_ == nullptr) {
      return nullptr;
    } else
      return array_;
  };
  /*
  Возвращает итератор начала вектора
  \return Итератор первого элемента
  */
  iterator begin() noexcept { return iterator(array_); };
  /*! Возвращает итератор конца вектора
  \return Итератор конца вектора
   */
  iterator end() noexcept { return iterator(array_ + size_); };
  /*
  Возвращает сonst-итератор начала вектора
  \return Const-итератор первого элемента
  */
  const_iterator cbegin() const noexcept { return const_iterator(array_); };
  /*! Возвращает сonst-итератор конца вектора
  \return Const-итератор конца вектора
  */
  const_iterator cend() const noexcept {
    return const_iterator(array_ + size_);
  };
  /*! Проверяет есть ли в контейнере элементы
  \return Пуст или не пуст контейнер
  */
  bool empty() const noexcept {
    bool result = false;
    if (array_ == nullptr) {
      result = true;
    }
    return result;
  };
  /*! Возвращает количество элементов в контейнере
  \return Количество элементов в контейнере
  */
  size_type size() const noexcept { return size_; };
  /*! Возвращает максимальное количество элементов, которые контейнер может
  хранить из-за ограничений реализации системы или библиотеки \return
  Максимальное количество элементов
  */
  size_type max_size() const noexcept {
    return std::allocator_traits<Alloc>::max_size(alloc);
  };
  /*! Увеличение емкости вектра до значения new_cap
  \param[in] new_cap - новая емкость вектора (количество новых элементов)
  */
  void reserve(size_type new_cap) {
    if (new_cap <= capacity_) {
      return;
    }
    ThrowFunction(size_, new_cap);
    capacity_ = new_cap;
  }
  /*! Возвращает количество элементов, для которых контейнер в данный момент
  выделил место \return Емкость выделенного в данный момент хранилища
  */
  size_type capacity() const noexcept { return capacity_; };
  /*! Уменьшение (удаление) емкости до размера вектора */
  void shrink_to_fit() {
    if (capacity_ == size_) {
      return;
    }
    ThrowFunction(size_, capacity_);
    capacity_ = size_;
  };
  /*! Удаление всех элементов из контейнера */
  void clear() noexcept {
    for (size_type i = 0; i < size_; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    size_ = 0;
  };
  /*! Производит вставку элемента в указанное место в контейнере
   \param[in] pos итератор, перед которым будет вставлен новый элемент
   \param[in] value значение элемента для вставки
   \return Итератор, указывающий на вставленное новое значение
  */
  iterator insert(iterator pos, const_reference value) {
    if (pos >= end()) {
      return pos;
    }
    if (size_ == capacity_) {
      pos = InsertReverse(pos, value);
      return pos;
    }
    size_++;
    ConstructDestroy(size_, value_type());
    auto iter = this->end();
    iter--;
    for (; iter > pos; iter--) {
      iter--;
      auto it = std::move_if_noexcept(*iter);
      iter++;
      *iter = std::move_if_noexcept(it);
    }
    *pos = value;
    return pos;
  };
  /*! Удаляет указанный элемент из контейнера
 \param[in] pos итератор элемента, который нужно удалить
 \return итератор, следующий за последним удаленным элементом
 */
  iterator erase(iterator pos) {
    if (pos >= this->end() || pos < this->begin()) {
      return pos;
    }
    auto it = end();
    it--;
    for (auto iter = pos; iter < it; iter++) {
      iter++;
      auto it = std::move_if_noexcept(*iter);
      iter--;
      *iter = std::move_if_noexcept(it);
    }
    size_--;
    return pos;
  };
  /*! Добавляет заданное значение элемента в конец контейнера
 \param[in] value значение элемента для добавления
 */
  void push_back(const_reference value) {
    if (capacity_ == 0) {
      size_++;
      capacity_++;
      AllocateMemory();
      ConstructDestroy(0, value);
      return;
    }
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    ConstructDestroy(size_, value);
    size_++;
  };
  /*! Удаляет последний элемент контейнера
   */
  void pop_back() {
    if (size_ < 1) {
      return;
    } else if (size_ == 1) {
      std::allocator_traits<Alloc>::destroy(alloc, array_);
    } else {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + size_);
      size_ = size_ - 1;
    }
  };
  /*! Заменяет содержимое и емкость контейнера другим
 \param[in] other контейнер для обмена содержимым
 */
  void swap(Vector &other) noexcept {
    std::swap(alloc, other.alloc);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(array_, other.array_);
  };
  /*! Изменяет размер контейнера, чтобы он содержал количество элементов
 \param[in] n новый размер контейнера
 */
  void resize(size_type n) {
    if (n == size_) {
      return;
    }
    if (n > capacity_) {
      reserve(n);
      size_ = n;
    }
    if (n < capacity_) {
      size_ = n;
    }
  };

 private:
  Alloc alloc;          //< экземпляр класса Allocator
  pointer array_;       //< указатель на данные вектора
  size_type size_;      //< размер вектора
  size_type capacity_;  //< количество выделенной памяти
  /*!
  Выделение памяти для данных вектора
  */
  void AllocateMemory() {
    array_ = std::allocator_traits<Alloc>::allocate(alloc, capacity_);
  }
  /*!
  Очищение памяти данных вектора
  */
  void DeleteMemory() {
    for (size_type i = 0; i < size_; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    std::allocator_traits<Alloc>::deallocate(alloc, array_, capacity_);
    array_ = nullptr;
  }
  /*!
  Выделение и удаление памяти вектора с проверкой на ошибки
  \param[in] size новый размер вектора
  \param[in] cap новый объем вектора
  */
  void ThrowFunction(size_type size, size_type cap) {
    pointer new_array = std::allocator_traits<Alloc>::allocate(alloc, cap);
    size_type i = 0;
    try {
      if (size_ == 0) {
        std::allocator_traits<Alloc>::construct(
            alloc, std::addressof(*(new_array + i)), T());
      }
      for (; i < size; ++i) {
        std::allocator_traits<Alloc>::construct(
            alloc, std::addressof(*(new_array + i)),
            std::move_if_noexcept(array_[i]));
      }
    } catch (...) {
      for (; i < size; ++i) {
        std::allocator_traits<Alloc>::destroy(alloc, new_array + i);
      }
      std::allocator_traits<Alloc>::deallocate(alloc, new_array, cap);
      throw;
    }
    for (size_type i = 0; i < size; ++i) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + i);
    }
    std::allocator_traits<Alloc>::deallocate(alloc, array_, cap);
    array_ = new_array;
  }
  /* Вспомогательный метода Insert()
 \param[in] pos итератор, перед которым будет вставлен новый элемент
 \param[in] value значение элемента для вставки
 \return Итератор, указывающий на вставленное новое значение
  */
  iterator InsertReverse(iterator pos, const_reference value) {
    auto iter = begin();
    size_type index = 0;
    for (size_type i = 0; i < size_; i++) {
      if (iter == pos) {
        index = i;
      }
      iter++;
    }
    reserve(capacity_ * 2);
    size_++;
    ConstructDestroy(size_, value_type());
    size_type i = size_;
    for (; i != index; i--) {
      i--;
      auto it = std::move_if_noexcept(array_[i]);
      i++;
      array_[i] = std::move_if_noexcept(it);
    }
    size_t j = 0;
    for (auto iter = begin(); iter < end(); ++iter) {
      if (j == i) {
        pos = iter;
      }
      j++;
    }
    array_[i] = value;
    return pos;
  }
  /* Вспомогательный метод вызова allocator_traits<Alloc>::construct в
    конструкции try catch для использования в других методах
  \param[in] shift сдвиг на элементов вектора
  \param[in] value значение элемента */
  void ConstructDestroy(size_type shift, const_reference value) {
    try {
      std::allocator_traits<Alloc>::construct(alloc,
                                              std::addressof(*(array_ + shift)),
                                              std::move_if_noexcept(value));
    } catch (...) {
      std::allocator_traits<Alloc>::destroy(alloc, array_ + shift);
      throw;
    }
  }
};
/*! Определение шаблоного класса итератора ветора. Первый параметр - тип данных,
второй параметр - значение типа данных bool для опеределения итератора - const
он или нет */
template <typename T, bool IsConst>
class CommonIterator {
 public:
  friend class Vector<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using size_type = size_t;
  using conditional_ptr = std::conditional_t<IsConst, const_pointer, pointer>;
  using conditional_ref =
      std::conditional_t<IsConst, const_reference, reference>;
  /*! Конструктор итератора по умолчанию*/
  CommonIterator() noexcept : value(nullptr){};
  /*! Параметризованный конструктор
  \param[out] current указатель на данные
   */
  CommonIterator(pointer current) : value(current) {}
  /*! Перегрузка опрератора +
  \param[in] n значение для прибавления к текущему
  \return ссылка на новое значение
  */
  conditional_ref operator+(int n) { return *(value + n); }
  /*! Перегрузка опрератора -
  \param[in] n значение для вычитания из текущего значения
  \return ссылка на новое значение
  */
  conditional_ref operator-(int n) { return *(value - n); }
  /*! Перегрузка опрератора ++
  \return *this
  */
  conditional_ref operator++(int) { return *(value++); }
  /*! Перегрузка опрератора --
  \return *this
  */
  conditional_ref operator--(int) { return *(value--); }
  /*! Перегрузка опрератора ++
  \return *this
  */
  conditional_ref operator++() { return *(value++); }
  /*! Перегрузка опрератора --
  \return *this
  */
  conditional_ref operator--() { return *(value--); }
  /*! Перегрузка опрератора <=
  \param[in] other другой итератор вектора для сравнения
  \return проверка на <=
  */
  bool operator<=(const CommonIterator &other) const {
    return (value <= other.value);
  }
  /*! Перегрузка опрератора >=
  \param[in] other другой итератор вектора для сравнения
  \return проверка на >=
  */
  bool operator>=(const CommonIterator &other) const {
    return (value >= other.value);
  }
  /*! Перегрузка опрератора <
  \param[in] other другой итератор вектора для сравнения
  \return проверка на <
  */
  bool operator<(const CommonIterator &other) const {
    return (value < other.value);
  }
  /*! Перегрузка опрератора >
  \param[in] other другой итератор вектора для сравнения
  \return проверка на >
  */
  bool operator>(const CommonIterator &other) const {
    return (value > other.value);
  }
  /*! Перегрузка опрератора !=
  \param[in] other другой итератор вектора для сравнения
  \return проверка на равенство данных
  */
  bool operator!=(const CommonIterator &other) const {
    return (value != other.value);
  }
  /*! Перегрузка опрератора ==
  \param[in] other другой итератор вектора для сравнения
  \return проверка на равенство данных
  */
  bool operator==(const CommonIterator &other) const {
    return (value == other.value);
  }
  /*! Перегрузка опрератора *
  \return значение данных вектора
  */
  conditional_ref operator*() const { return *value; }
  /*! Перегрузка опрератора ->
  \return значение данных вектора
  */
  conditional_ptr operator->() const { return value; }

 private:
  conditional_ptr value;  //< значение элемента вектора
};

};      // namespace containers
#endif  //_VECTOR_H_

#include "DoublyLinkedList.h"
#include <stdexcept>

namespace containers {

    // Конструктор по умолчанию
    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор со списком инициализации
    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const std::initializer_list<T> init)
        : head(nullptr), tail(nullptr), size(0) {
        for (const auto& value : init) {
            push_back(value);
        }
    }

    // Конструктор копирования
    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
        : head(nullptr), tail(nullptr), size(0) {
        copyFrom(other);
    }

    // Конструктор перемещения
    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept
        : head(other.head), tail(other.tail), size(other.size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // Деструктор
    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        clear();
    }

    // Оператор присваивания копированием
    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    // Оператор присваивания перемещением
    template<typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size = other.size;
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Оператор вывода в поток
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        os << list.ToString();
        return os;
    }

    // Оператор ввода из потока
    template<typename T>
    std::istream& operator>>(std::istream& is, DoublyLinkedList<T>& list) {
        list.clear();
        T value;
        while (is >> value) {
            list.push_back(value);
            if (is.peek() == '\n' || is.peek() == EOF) break;
        }
        return is;
    }

    // Вспомогательный метод копирования
    template<typename T>
    void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    // Добавление в конец
    template<typename T>
    void DoublyLinkedList<T>::push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    // Добавление в начало
    template<typename T>
    void DoublyLinkedList<T>::push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    // Вставка по индексу
    template<typename T>
    void DoublyLinkedList<T>::insert(const size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            push_front(value);
            return;
        }
        if (index == size) {
            push_back(value);
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        ++size;
    }

    // Удаление с конца
    template<typename T>
    void DoublyLinkedList<T>::pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        --size;
    }

    // Удаление с начала
    template<typename T>
    void DoublyLinkedList<T>::pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        --size;
    }

    // Удаление по индексу
    template<typename T>
    void DoublyLinkedList<T>::erase(const size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == size - 1) {
            pop_back();
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        --size;
    }

    // Удаление по значению
    template<typename T>
    bool DoublyLinkedList<T>::remove(const T& value) {
        int index = find(value);
        if (index != -1) {
            erase(index);
            return true;
        }
        return false;
    }

    // Поиск элемента
    template<typename T>
    int DoublyLinkedList<T>::find(const T& value) const {
        Node<T>* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return static_cast<int>(index);
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    // Изменение элемента
    template<typename T>
    void DoublyLinkedList<T>::modify(const size_t index, const T& value) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    // Оператор индексирования (неконстантный)
    template<typename T>
    T& DoublyLinkedList<T>::operator[](const size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Оператор индексирования (константный)
    template<typename T>
    const T& DoublyLinkedList<T>::operator[](const size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Получение размера
    template<typename T>
    size_t DoublyLinkedList<T>::getSize() const {
        return size;
    }

    // Проверка на пустоту
    template<typename T>
    bool DoublyLinkedList<T>::isEmpty() const {
        return size == 0;
    }

    // Очистка списка
    template<typename T>
    void DoublyLinkedList<T>::clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    // Сериализация в строку
    template<typename T>
    std::string DoublyLinkedList<T>::ToString() const {
        std::stringstream ss;
        ss << "[";
        Node<T>* current = head;
        while (current != nullptr) {
            ss << current->data;
            if (current->next != nullptr) {
                ss << " <-> ";
            }
            current = current->next;
        }
        ss << "]";
        return ss.str();
    }

    // Получение головы списка
    template<typename T>
    Node<T>* DoublyLinkedList<T>::getHead() const {
        return head;
    }

    // Явная инстанциация для типа int
    template class DoublyLinkedList<int>;
    template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<int>&);
    template std::istream& operator>>(std::istream&, DoublyLinkedList<int>&);

}
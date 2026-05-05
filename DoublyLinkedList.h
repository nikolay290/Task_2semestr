#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>
#include "Node.h"

namespace containers {

    /**
     * @brief Класс линейного двусвязного списка
     * @tparam T тип данных, хранящихся в списке
     */
    template<typename T>
    class DoublyLinkedList {
    private:
        Node<T>* head;    ///< Указатель на начало списка
        Node<T>* tail;    ///< Указатель на конец списка
        size_t size;      ///< Размер списка

        /**
         * @brief Копирует содержимое другого списка
         * @param other - список для копирования
         */
        void copyFrom(const DoublyLinkedList<T>& other);

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        DoublyLinkedList();

        /**
         * @brief Конструктор со списком инициализации
         * @param init - список инициализации
         */
        DoublyLinkedList(const std::initializer_list<T> init);

        /**
         * @brief Конструктор копирования
         * @param other - другой список
         */
        DoublyLinkedList(const DoublyLinkedList<T>& other);

        /**
         * @brief Конструктор перемещения
         * @param other - другой список
         */
        DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept;

        /**
         * @brief Деструктор
         */
        ~DoublyLinkedList();

        /**
         * @brief Оператор присваивания копированием
         * @param other - другой список
         * @return ссылка на текущий объект
         */
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

        /**
         * @brief Оператор присваивания перемещением
         * @param other - другой список
         * @return ссылка на текущий объект
         */
        DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& other) noexcept;

        /**
         * @brief Оператор сдвига влево (вывод в поток)
         * @param os - поток вывода
         * @param list - список для вывода
         * @return ссылка на поток вывода
         */
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list);

        /**
         * @brief Оператор сдвига вправо (ввод из потока)
         * @param is - поток ввода
         * @param list - список для ввода
         * @return ссылка на поток ввода
         */
        template<typename U>
        friend std::istream& operator>>(std::istream& is, DoublyLinkedList<U>& list);

        /**
         * @brief Вставка элемента в конец списка
         * @param value - значение элемента
         */
        void push_back(const T& value);

        /**
         * @brief Вставка элемента в начало списка
         * @param value - значение элемента
         */
        void push_front(const T& value);

        /**
         * @brief Вставка элемента по индексу
         * @param index - позиция для вставки
         * @param value - значение элемента
         */
        void insert(const size_t index, const T& value);

        /**
         * @brief Удаление элемента из конца списка
         */
        void pop_back();

        /**
         * @brief Удаление элемента из начала списка
         */
        void pop_front();

        /**
         * @brief Удаление элемента по индексу
         * @param index - позиция элемента
         */
        void erase(const size_t index);

        /**
         * @brief Удаление элемента по значению (первое вхождение)
         * @param value - значение для удаления
         * @return true, если элемент найден и удален
         */
        bool remove(const T& value);

        /**
         * @brief Поиск элемента по значению
         * @param value - значение для поиска
         * @return индекс элемента или -1, если не найден
         */
        int find(const T& value) const;

        /**
         * @brief Изменение элемента по индексу
         * @param index - позиция элемента
         * @param value - новое значение
         */
        void modify(const size_t index, const T& value);

        /**
         * @brief Оператор доступа по индексу (неконстантный)
         * @param index - позиция элемента
         * @return ссылка на элемент
         */
        T& operator[](const size_t index);

        /**
         * @brief Оператор доступа по индексу (константный)
         * @param index - позиция элемента
         * @return константная ссылка на элемент
         */
        const T& operator[](const size_t index) const;

        /**
         * @brief Получение размера списка
         * @return количество элементов
         */
        size_t getSize() const;

        /**
         * @brief Проверка, пуст ли список
         * @return true, если список пуст
         */
        bool isEmpty() const;

        /**
         * @brief Очистка списка
         */
        void clear();

        /**
         * @brief Сериализация в строку
         * @return строковое представление списка
         */
        std::string ToString() const;

        /**
         * @brief Получение указателя на начало списка
         * @return указатель на голову списка
         */
        Node<T>* getHead() const;
    };

}
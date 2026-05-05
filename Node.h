#pragma once

namespace containers {

    /**
     * @brief Класс узла двусвязного списка
     * @tparam T тип данных, хранящихся в узле
     */
    template<typename T>
    class Node {
    public:
        T data;           ///< Данные, хранящиеся в узле
        Node<T>* next;    ///< Указатель на следующий узел
        Node<T>* prev;    ///< Указатель на предыдущий узел

        /**
         * @brief Конструктор узла
         * @param value - значение для хранения в узле
         */
        explicit Node(const T& value);
    };

}
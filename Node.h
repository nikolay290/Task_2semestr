#pragma once

namespace containers {

    /**
     * @brief Класс узла двусвязного списка
     * @tparam T тип данных, хранящихся в узле
     */
    template<typename T>
    class Node {
    public:
        T data;          
        Node<T>* next;    
        Node<T>* prev;    

        /**
         * @brief Конструктор узла
         * @param value - значение для хранения в узле
         */
        explicit Node(const T& value);
    };

}

#pragma once
#include <iostream>

namespace geometry {
    class Point {
    private:
        /**
        * @brief x - координата точки по оси OX
        */
        double x;

        /**
        * @brief y - координата точки по оси OY
        */
        double y;

    public:
        /**
        * @brief Конструктор, создаёт точку с координатами x,y
        * @param x - координата точки по оси OX
        * @param y - координата точки по оси OY
        */
        Point(double x = 0.0, double y = 0.0);

        /**
        * @brief Конструктор копирования
        * @param other - другая точка
        */
        Point(const Point& other);

        /**
        * @brief Конструктор перемещения
        * @param other - другая точка
        */
        Point(Point&& other);

        /**
         * @brief Получение координаты x
         * @return Значение координаты x
         */
        double getX() const;

        /**
         * @brief Получение координаты y
         * @return Значение координаты y
         */
        double getY() const;

        /**
         * @brief Вычисление расстояния до другой точки
         * @param other Другая точка
         * @return Расстояние между точками
         */
        double distanceTo(const Point& other) const;

        /**
         * @brief Оператор присваивания (копирование)
         * @param other Другая точка
         * @return ссылка на текущий объект
         */
        Point& operator=(const Point& other);

        /**
         * @brief Оператор присваивания (перемещение)
         * @param other Другая точка
         * @return ссылка на текущий объект
         */
        Point& operator=(Point&& other);

        /**
         * @brief Проверка точек на совпадение
         * @param other Другая точка
         * @return true, если точки совпадают
         */
        bool operator==(const Point& other) const;

        /**
         * @brief Проверка точек на несовпадение
         * @param other Другая точка
         * @return true, если точки не совпадают
         */
        bool operator!=(const Point& other) const;

        /**
         * @brief Оператор вывода в поток
         * @param os Выходной поток
         * @param point Точка для вывода
         */
        friend std::ostream& operator<<(std::ostream& os, const Point& point);

        /**
         * @brief Оператор ввода из потока
         * @param is Входной поток
         * @param point Точка для ввода
         */
        friend std::istream& operator>>(std::istream& is, Point& point);
    };
}

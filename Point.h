#pragma once
#include <iostream>

namespace geometry {
    class Point {
    private:
        /**
        * @brief x - координата точки по оси OX
        */
        double x=0;
        
        /**
        * @brief y - координата точки по оси OY
        */
        double y=0;

    public:
        /**
        * @brief Конструктор, создаёт точку с координатами x,y
        * @param x - координата точки по оси OX
        * @param y - координата точки по оси OY
        * @return Значение координаты x
        */
        Point(double x = 0.0, double y = 0.0);

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
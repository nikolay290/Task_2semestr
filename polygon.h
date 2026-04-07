#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "point.h"

namespace geometry {
    class Polygon {
    protected:
        std::vector<Point> vertices;

    public:
        /**
        * @brief конструктор по умолчанию
        */
        Polygon() = default;

        /**
        * @brief виртуальный деструктор
        */
        virtual ~Polygon() = default;

        /**
        * @brief сериализация в строку
        * @return строковое представление многоугольника
        */
        virtual std::string ToString() const = 0;

        /**
        * @brief вычисляет площадь многоугольника
        * @return площадь
        */
        virtual double getArea() const = 0;

        /**
        * @brief вычисляет периметр многоугольника
        * @return периметр
        */
        virtual double getPerimeter() const = 0;

        /**
        * @brief вычисляет радиус описанной окружности
        * @return радиус описанной окружности
        */
        virtual double getCircumradius() const = 0;

        /**
        * @brief метод чтения из стандартного потока ввода
        * @param is - входной поток
        */
        virtual void read(std::istream& is) = 0;

        /**
        * @brief оператор вывода в поток
        * @param os - выходной поток
        * @param polygon - многоугольник для вывода
        * @return ссылка на поток
        */
        friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);

        /**
        * @brief оператор ввода из потока
        * @param is - входной поток
        * @param polygon - многоугольник для ввода
        * @return ссылка на поток
        */
        friend std::istream& operator>>(std::istream& is, Polygon& polygon);

        /**
        * @brief статическая сериализация в строку
        * @param polygon - многоугольник для сериализации
        * @return строковое представление
        */
        static std::string ToString(const Polygon& polygon);

        /**
        * @brief статический метод чтения из потока
        * @param is - входной поток
        * @return указатель на созданный многоугольник
        */
        static Polygon* readFromStream(std::istream& is);
    };
}
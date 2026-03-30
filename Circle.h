#pragma once
#include <iostream>

class Circle
{
private:
    /**
    * @brief x - координата центра окружности по оси OX
    */
    double x;
    /**
    * @brief y - координата центра окружности по оси OY
    */
    double y;
    /**
    * @brief radius - радиус окружности
    */
    double radius;

public:

    /**
    * @brief конструктор, создает окружность с указанными параметрами
    * @param centerX - координата центра по оси OX
    * @param centerY - координата центра по оси OY
    * @param r - радиус окружности
    */
    Circle(const double centerX, const double centerY, const double r);

    /**
    * @brief вычисление площади круга
    * @return площадь круга
    */
    double getArea() const;

    /**
    * @brief вычисление длины окружности
    * @return длина окружности
    */
    double getCircumference() const;



    /**
    * @brief получение "разрешения" у класса на доступ к private для вывода
    * @param os
    * @param circle - окружность для вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);

    /**
    * @brief получение "разрешения" у класса на доступ к private для ввода
    * @param is
    * @param circle - окружность для ввода
    */
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};
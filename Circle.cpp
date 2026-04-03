#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <limits>
#include "Circle.h"

using namespace std;


Circle::Circle(const double centerX, const double centerY, const double r) : x(centerX), y(centerY), radius(r)
{

}

// Вычисление площади круга
double Circle::getArea() const
{
    return M_PI * radius * radius;
}

// Вычисление длины окружности
double Circle::getCircumference() const
{
    return 2 * M_PI * radius;
}

ostream& operator<<(ostream& os, const Circle& circle)
{
    os << "Центр: (" << circle.x << ";" << circle.y
        << "), Радиус: " << circle.radius;
    return os;
}


istream& operator>>(istream& is, Circle& circle)
{
    cout << "Введите координаты центра (x y): ";
    is >> circle.x >> circle.y;
    if (!circle.x || !circle.y)
    {
        cout << "Ошбика обе координаты должны быть числами";
        exit(1);
    }
    cout << "Введите радиус: ";
    is >> circle.radius;

    if (circle.radius < DBL_EPSILON)
    {
        cout << "Ошбика радиус должен быть положительным";
        exit(1);
    }

    return is;
}













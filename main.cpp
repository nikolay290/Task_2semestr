#include <iostream>
#include <clocale>
#include "Circle.h"

using namespace std;

/**
* @brief точка входа в программу
* @return 0, если программа выполнена правильно
*/
int main(void)
{
    setlocale(LC_ALL, "Ru");


    Circle circle1(2.5, -1.0, 3.0);
    cout << "Окружность 1: " << circle1 << endl;
    cout << "Площадь круга: " << circle1.getArea() << endl;
    cout << "Длина окружности: " << circle1.getCircumference() << endl;
    cout << endl;
    

    Circle circle2(0,0,0);
    cout << "Введите данные для окружности 2:" << endl;
    cin >> circle2;
    cout << "Вы ввели: " << circle2 << endl;
    cout << "Площадь: " << circle2.getArea() << endl;
    cout << "Длина окружности: " << circle2.getCircumference() << endl;
    cout << endl;
    cout << "Программа выполнена успешно" << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>
#include "pentagon.h"
#include <clocale>

/**
* @brief точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main(void) {
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "=== Демонстрация работы с классами Polygon и Pentagon ===\n\n";
        std::cout << "1. Создание правильного пятиугольника через точки:\n";
        geometry::Point p1(1, 0);
        geometry::Point p2((sqrt(5)-1)/4, sqrt(10+2*sqrt(5))/4);
        geometry::Point p3(-(sqrt(5) + 1) / 4, sqrt(10 - 2 * sqrt(5)) / 4);
        geometry::Point p4(-(sqrt(5) + 1) / 4, -sqrt(10 - 2 * sqrt(5)) / 4);
        geometry::Point p5((sqrt(5) - 1) / 4, -sqrt(10 + 2 * sqrt(5)) / 4);

        geometry::Pentagon pentagon1(p1, p2, p3, p4, p5);
        std::cout << "Пятиугольник 1: " << pentagon1 << "\n";
        std::cout << "Площадь: " << pentagon1.getArea() << "\n";
        std::cout << "Периметр: " << pentagon1.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << pentagon1.getCircumradius() << "\n\n";


        std::cout << "2. Создание пятиугольника через пары чисел:\n";

        double x1 = 1.0;
        double y1 = 0.0;


        double x2 = (sqrt(5) - 1) / 4;
        double y2 = sqrt(10 + 2 * sqrt(5)) / 4;


        double x3 = -(sqrt(5) + 1) / 4;
        double y3 = sqrt(10 - 2 * sqrt(5)) / 4;

        double x4 = -(sqrt(5) + 1) / 4;
        double y4 = -sqrt(10 - 2 * sqrt(5)) / 4;

        double x5 = (sqrt(5) - 1) / 4;
        double y5 = -sqrt(10 + 2 * sqrt(5)) / 4;
        geometry::Pentagon pentagon2(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
        std::cout << "Пятиугольник 2: " << pentagon2 << "\n";
        std::cout << "Площадь: " << pentagon2.getArea() << "\n";
        std::cout << "Периметр: " << pentagon2.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << pentagon2.getCircumradius() << "\n\n";

        std::cout << "3. Коллекция объектов базового типа:\n";
        std::vector<std::unique_ptr<geometry::Polygon>> polygons;

        polygons.push_back(std::make_unique<geometry::Pentagon>(pentagon1));
        polygons.push_back(std::make_unique<geometry::Pentagon>(pentagon2));


        double x11 = 2;
        double y11 = 0;


        double x12 = 2 * (sqrt(5) - 1) / 4;
        double y12 = 2 * sqrt(10 + 2 * sqrt(5)) / 4;


        double x13 = -2 * (sqrt(5) + 1) / 4;
        double y13 = 2 * sqrt(10 - 2 * sqrt(5)) / 4;


        double x14 = -2 * (sqrt(5) + 1) / 4;
        double y14 = -2 * sqrt(10 - 2 * sqrt(5)) / 4;


        double x15 = 2 * (sqrt(5) - 1) / 4;
        double y15 = -2 * (sqrt(10 + 2 * sqrt(5))) / 4;
        geometry::Pentagon pentagon3(x11, y11, x12, y12, x13, y13, x14, y14, x15, y15);
        polygons.push_back(std::make_unique<geometry::Pentagon>(pentagon3));

        std::cout << "Итерация по коллекции:\n";
        for (size_t i = 0; i < polygons.size(); ++i) {
            std::cout << "Объект " << (i + 1) << ": " << *polygons[i] << "\n";
            std::cout << "  Площадь: " << polygons[i]->getArea() << "\n";
            std::cout << "  Периметр: " << polygons[i]->getPerimeter() << "\n";
            std::cout << "  Радиус описанной окружности: " << polygons[i]->getCircumradius() << "\n\n";
        }

        std::cout << "4. Демонстрация операторов сравнения:\n";
        std::cout << "pentagon4 == pentagon5: " << (pentagon1 == pentagon2 ? "true" : "false") << "\n";
        std::cout << "pentagon4 == pentagon6: " << (pentagon2 == pentagon1 ? "true" : "false") << "\n";
        std::cout << "pentagon4 != pentagon6: " << (pentagon1 != pentagon2 ? "true" : "false") << "\n\n";

        std::cout << "5. Демонстрация статического метода ToString:\n";
        std::cout << geometry::Pentagon::ToString(pentagon1) << "\n\n";

        std::cout << "6. Демонстрация статического метода readFromStream:\n";
        std::cout << "Введите вершины пятиугольника в формате (x, y) (5 раз):\n";
        std::cout << "Пример: (2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)\n";
        auto pentagon7 = geometry::Pentagon::readFromStream(std::cin);
        std::cout << "Прочитанный пятиугольник: " << pentagon7 << "\n\n";

        std::cout << "7. Попытка создания некорректного пятиугольника (ожидается исключение):\n";
        try {
            // Некорректный пятиугольник (не все стороны равны)
            geometry::Pentagon invalidPentagon(0, 0, 2, 0, 2, 2, 0, 2, 1, 3);
        }
        catch (const std::exception& e) {
            std::cout << "Исключение: " << e.what() << "\n";
        }

        std::cout << "\n8. Демонстрация получения вершин:\n";
        auto vertices = pentagon1.getVertices();
        std::cout << "Вершины пятиугольника 1:\n";
        for (size_t i = 0; i < vertices.size(); ++i) {
            std::cout << "  Вершина " << (i + 1) << ": " << vertices[i] << "\n";
        }

        std::cout << "\n9. Демонстрация оператора ввода для класса Point:\n";
        std::cout << "Введите точку в формате (x, y): ";
        geometry::Point testPoint;
        std::cin >> testPoint;
        std::cout << "Вы ввели точку: " << testPoint << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
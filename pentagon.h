#pragma once
#include "polygon.h"
#include <vector>
#include <iostream>

namespace geometry {
    class Pentagon : public Polygon {
    private:
        static const size_t VERTEX_COUNT = 5;

        /**
         * @brief Проверяет корректность правильного пятиугольника
         * @return true, если все условия выполнены
         */
        bool isValidPentagon() const;

        /**
         * @brief Вычисляет угол между тремя точками
         * @param p1 - первая точка
         * @param p2 - вторая точка (вершина)
         * @param p3 - третья точка
         * @return угол в радианах
         */
        double angleBetweenPoints(const Point& p1, const Point& p2, const Point& p3) const;

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Pentagon();

        /**
         * @brief Конструктор через вершины-точки
         */
        Pentagon(const Point& p1, const Point& p2, const Point& p3,
            const Point& p4, const Point& p5);

        /**
         * @brief Конструктор через координаты вершин
         */
        Pentagon(const double x1, const double y1, const double x2, const double y2,
            const double x3, const double y3, const double x4, const double y4,
            const double x5, const double y5);

        /**
         * @brief Конструктор копирования
         * @param other - другой объект Pentagon
         */
        Pentagon(const Pentagon& other);

        /**
         * @brief Конструктор перемещения
         * @param other - другой объект Pentagon
         */
        Pentagon(Pentagon&& other);

        /**
         * @brief Деструктор
         */
        ~Pentagon() = default;

        /**
         * @brief Сериализация в строку
         */
        std::string ToString() const override;

        /**
         * @brief Вычисляет площадь
         */
        double getArea() const override;

        /**
         * @brief Вычисляет периметр
         */
        double getPerimeter() const override;

        /**
         * @brief Вычисляет радиус описанной окружности
         */
        double getCircumradius() const override;

        /**
         * @brief Чтение из потока
         */
        void read(std::istream& is) override;

        /**
         * @brief Оператор присваивания (копирование)
         * @param other - другой объект Pentagon
         * @return ссылка на текущий объект
         */
        Pentagon& operator=(const Pentagon& other);

        /**
         * @brief Оператор присваивания (перемещение)
         * @param other - другой объект Pentagon
         * @return ссылка на текущий объект
         */
        Pentagon& operator=(Pentagon&& other);

        /**
         * @brief Оператор сравнения равенства
         * @param other - другой объект Pentagon
         * @return true, если равны
         */
        bool operator==(const Pentagon& other) const;

        /**
         * @brief Оператор сравнения неравенства
         * @param other - другой объект Pentagon
         * @return true, если не равны
         */
        bool operator!=(const Pentagon& other) const;

        /**
         * @brief Оператор вывода в поток
         * @param os - выходной поток
         * @param pentagon - объект Pentagon
         * @return ссылка на поток
         */
        friend std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon);

        /**
         * @brief Оператор ввода из потока
         * @param is - входной поток
         * @param pentagon - объект Pentagon
         * @return ссылка на поток
         */
        friend std::istream& operator>>(std::istream& is, Pentagon& pentagon);

        /**
         * @brief Статический метод чтения из потока
         */
        static Pentagon readFromStream(std::istream& is);

        /**
         * @brief Получение всех вершин
         */
        std::vector<Point> getVertices() const;
    };
}

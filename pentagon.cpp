#define _USE_MATH_DEFINES
#include "pentagon.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <utility>

namespace geometry {

    Pentagon::Pentagon()
    {
    }

    Pentagon::Pentagon(const Point& p1, const Point& p2, const Point& p3,
        const Point& p4, const Point& p5)
    {
        vertices.push_back(p1);
        vertices.push_back(p2);
        vertices.push_back(p3);
        vertices.push_back(p4);
        vertices.push_back(p5);

        if (!isValidPentagon()) {
            std::cout << "Ошибка: точки не образуют правильный пятиугольник!" << std::endl;
        }
    }

    Pentagon::Pentagon(const double x1, const double y1, const double x2, const double y2,
        const double x3, const double y3, const double x4, const double y4,
        const double x5, const double y5)
    {
        vertices.push_back(Point(x1, y1));
        vertices.push_back(Point(x2, y2));
        vertices.push_back(Point(x3, y3));
        vertices.push_back(Point(x4, y4));
        vertices.push_back(Point(x5, y5));

        if (!isValidPentagon()) {
            std::cout << "Ошибка: точки не образуют правильный пятиугольник!" << std::endl;
        }
    }

    Pentagon::Pentagon(const Pentagon& other)
    {
        for (const auto& p : other.vertices) {
            this->vertices.push_back(p);
        }
    }

    Pentagon::Pentagon(Pentagon&& other)
    {
        std::swap(this->vertices, other.vertices);
    }

    double Pentagon::angleBetweenPoints(const Point& p1, const Point& p2, const Point& p3) const {
        double v1x = p1.getX() - p2.getX();
        double v1y = p1.getY() - p2.getY();
        double v2x = p3.getX() - p2.getX();
        double v2y = p3.getY() - p2.getY();

        double dot = v1x * v2x + v1y * v2y;
        double mag1 = std::sqrt(v1x * v1x + v1y * v1y);
        double mag2 = std::sqrt(v2x * v2x + v2y * v2y);

        if (mag1 < std::numeric_limits<double>::epsilon() ||
            mag2 < std::numeric_limits<double>::epsilon()) {
            return 0.0;
        }

        double cosAngle = dot / (mag1 * mag2);
        cosAngle = std::max(-1.0, std::min(1.0, cosAngle));

        return std::acos(cosAngle);
    }

    bool Pentagon::isValidPentagon() const {
        if (vertices.size() != VERTEX_COUNT) {
            return false;
        }

        std::vector<double> sides;
        for (size_t i = 0; i < VERTEX_COUNT; ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % VERTEX_COUNT];
            long double side = p1.distanceTo(p2);

            // Сторона должна быть положительным числом
            if (side <= std::numeric_limits<double>::epsilon()) {
                return false;
            }
            sides.push_back(side);
        }

        for (size_t i = 1; i < VERTEX_COUNT; ++i) {
            if ((double)std::fabs(sides[i] - sides[0]) > std::numeric_limits<double>::epsilon()) {
                return false;
            }
        }

        double expectedAngle = 3.0 * M_PI / 5.0;

        for (size_t i = 0; i < VERTEX_COUNT; ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % VERTEX_COUNT];
            const Point& p3 = vertices[(i + 2) % VERTEX_COUNT];

            double ang = angleBetweenPoints(p1, p2, p3);
            if (std::abs(ang - expectedAngle) > std::numeric_limits<double>::epsilon()) {
                return false;
            }
        }

        // Проверка, что никакие три точки не лежат на одной прямой
        for (size_t i = 0; i < VERTEX_COUNT; ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % VERTEX_COUNT];
            const Point& p3 = vertices[(i + 2) % VERTEX_COUNT];

            double area2 = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
                (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());

            if (std::abs(area2) < std::numeric_limits<double>::epsilon()) {
                return false; // Три точки на одной прямой
            }
        }

        return true;
    }

    std::string Pentagon::ToString() const {
        std::stringstream ss;
        ss << "Pentagon[";
        for (size_t i = 0; i < vertices.size(); ++i) {
            ss << "v" << (i + 1) << "=" << vertices[i];
            if (i < vertices.size() - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }

    double Pentagon::getArea() const {
        // Площадь правильного пятиугольника через сторону
        double side = getPerimeter() / VERTEX_COUNT;
        double area = (1.0 / 4.0) * std::sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))) * side * side;
        return area;
    }

    double Pentagon::getPerimeter() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        double perimeter = 0.0;
        for (size_t i = 0; i < VERTEX_COUNT; ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % VERTEX_COUNT];
            perimeter += p1.distanceTo(p2);
        }
        return perimeter;
    }

    double Pentagon::getCircumradius() const {
        double side = getPerimeter() / VERTEX_COUNT;
        double radius = side / (2.0 * std::sin(M_PI / 5.0));
        return radius;
    }

    void Pentagon::read(std::istream& is) {
        std::vector<Point> newVertices;
        newVertices.resize(VERTEX_COUNT);

        for (size_t i = 0; i < VERTEX_COUNT; ++i) {
            is >> newVertices[i];
        }

        vertices = newVertices;
        if (!isValidPentagon()) {
            std::cout << "Ошибка: точки не образуют правильный пятиугольник!" << std::endl;
        }
    }

    Pentagon& Pentagon::operator=(const Pentagon& other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->vertices.clear();
        for (const auto& p : other.vertices) {
            this->vertices.push_back(p);
        }
        return *this;
    }

    Pentagon& Pentagon::operator=(Pentagon&& other)
    {
        if (this == &other)
        {
            return *this;
        }
        std::swap(this->vertices, other.vertices);
        return *this;
    }

    bool Pentagon::operator==(const Pentagon& other) const
    {
        if (this->vertices.size() != other.vertices.size())
        {
            return false;
        }

        for (size_t i = 0; i < this->vertices.size(); ++i)
        {
            if (this->vertices[i] != other.vertices[i])
            {
                return false;
            }
        }
        return true;
    }

    bool Pentagon::operator!=(const Pentagon& other) const
    {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon)
    {
        os << pentagon.ToString();
        return os;
    }

    std::istream& operator>>(std::istream& is, Pentagon& pentagon)
    {
        pentagon.read(is);
        return is;
    }

    Pentagon Pentagon::readFromStream(std::istream& is) {
        Pentagon pentagon;
        pentagon.read(is);
        return pentagon;
    }

    std::vector<Point> Pentagon::getVertices() const {
        return vertices;
    }
}

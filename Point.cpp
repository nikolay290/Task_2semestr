#include "Point.h"
#include <cmath>
#include <limits>
#include <iostream>

namespace geometry {
    Point::Point(const double x, const double y) : x(x), y(y)
    {
    }

    Point::Point(const Point& other) : x(other.x), y(other.y)
    {
    }

    Point::Point(Point&& other) : x(other.x), y(other.y)
    {
        other.x = 0.0;
        other.y = 0.0;
    }

    double Point::getX() const
    {
        return x;
    }

    double Point::getY() const
    {
        return y;
    }

    double Point::distanceTo(const Point& other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    Point& Point::operator=(const Point& other)
    {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Point& Point::operator=(Point&& other)
    {
        if (this != &other) {
            x = other.x;
            y = other.y;
            other.x = 0.0;
            other.y = 0.0;
        }
        return *this;
    }

    bool Point::operator==(const Point& other) const {
        return std::abs(x - other.x) < std::numeric_limits<double>::epsilon() &&
            std::abs(y - other.y) < std::numeric_limits<double>::epsilon();
    }

    bool Point::operator!=(const Point& other) const {
        return !(*this == other);
    }

    std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    std::istream& operator>>(std::istream& is, Point& point) {
        char comma, bracket;
        is >> bracket >> point.x >> comma >> point.y >> bracket;
        return is;
    }
}

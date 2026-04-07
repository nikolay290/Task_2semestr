#include "Point.h"
#include <cmath>
#include <limits>
#include <iostream>

namespace geometry {
    Point::Point(const double x, const double y) : x(x), y(y)
    {
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
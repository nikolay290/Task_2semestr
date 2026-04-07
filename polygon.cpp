#include "polygon.h"

namespace geometry {
    std::ostream& operator<<(std::ostream& os, const Polygon& polygon) {
        os << polygon.ToString();
        return os;
    }

    std::istream& operator>>(std::istream& is, Polygon& polygon) {
        polygon.read(is);
        return is;
    }

    std::string Polygon::ToString(const Polygon& polygon) {
        return polygon.ToString();
    }

    Polygon* Polygon::readFromStream(std::istream& is) {
        return nullptr;
    }
}
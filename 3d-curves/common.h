#pragma once

#include <ostream>

namespace curve {
    enum class CurveType { CIRCLE, ELLIPSE, HELIX };

    struct Point3D {
        Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
        double x, y, z;

        std::ostream& operator<<(std::ostream& os) const {
            os << "{" << x << ", " << y << ", " << z << "}";
        }
    };

    struct Vector3D {
        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
        double x, y, z;

        std::ostream& operator<<(std::ostream& os) const {
            os << "{" << x << ", " << y << ", " << z << "}";
        }
    };
} // namespace curve
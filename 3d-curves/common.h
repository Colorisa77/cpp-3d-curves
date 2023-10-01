#pragma once

#include <ostream>

namespace curve {
    enum class CurveType { CIRCLE, ELLIPSE, HELIX };

    inline std::ostream& operator<<(std::ostream& os, const CurveType type) {
        switch(type) {
            case CurveType::CIRCLE:
                os << "CIRCLE";
                break;
            case CurveType::ELLIPSE:
                os << "ELLIPSE";
                break;
            case CurveType::HELIX:
                os << "HELIX";
                break;
        }
        return os;
    }

    struct Point3D {
        Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
        double x, y, z;

        bool operator==(const Point3D& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const Point3D& point) {
        os << "{" << point.x << ", " << point.y << ", " << point.z << "}";
        return os;
    }

    struct Vector3D {
        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
        double x, y, z;

        bool operator==(const Vector3D& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const Vector3D& vector) {
        os << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}";
        return os;
    }
} // namespace curve
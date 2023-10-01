#include "ellipse.h"

#include <cmath>

namespace ellipse {
    Ellipse::Ellipse(curve::CurveType type, double axis_x, double axis_y)
    : type_(type)
    , axis_x_(axis_x)
    , axis_y_(axis_y) {
    }

    curve::Point3D Ellipse::GetPoint(double t) const {
        return {GetX(t), GetY(t), GetZ(t)};
    }

    curve::Vector3D Ellipse::GetDerivative(double t) const {
        return {GetDerivativeX(t), GetDerivativeY(t), GetDerivativeZ(t)};
    }

    curve::CurveType Ellipse::GetCurveType() const {
        return type_;
    }

    double Ellipse::GetAxisX() const {
        return axis_x_;
    }

    double Ellipse::GetAxisY() const {
        return axis_y_;
    }

    double Ellipse::GetX(double t) const {
        return axis_x_ * std::cos(t);
    }

    double Ellipse::GetY(double t) const {
        return axis_y_ * std::sin(t);
    }

    double Ellipse::GetZ(double t) const {
        (void)t;
        return 0.0;
    }

    double Ellipse::GetDerivativeX(double t) const {
        return axis_x_ * (-std::sin(t));
    }

    double Ellipse::GetDerivativeY(double t) const {
        return axis_y_ * std::cos(t);
    }

    double Ellipse::GetDerivativeZ(double t) const {
        (void)t;
        return 0.0;
    }

} // namespace ellipse
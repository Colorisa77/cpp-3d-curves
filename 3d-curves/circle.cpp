#include "circle.h"

#include <cmath>

namespace circle {
    Circle::Circle(double radius)
    : radius_(radius){
    }

    curve::Point3D Circle::GetPoint(double t) const {
        return {GetX(t), GetY(t), GetZ(t)};
    }

    curve::Vector3D Circle::GetDerivative(double t) const {
        return {GetDerivativeX(t), GetDerivativeY(t), GetDerivativeZ(t)};
    }

    double Circle::GetX(double t) const {
        return radius_ * std::cos(t);
    }

    double Circle::GetY(double t) const {
        return radius_ * std::sin(t);
    }

    double Circle::GetZ(double t) const {
        (void)t;
        return 0.0;
    }

    double Circle::GetRadius() const {
        return radius_;
    }

    double Circle::GetDerivativeX(double t) const {
        return -radius_ * std::sin(t);
    }

    double Circle::GetDerivativeY(double t) const {
        return radius_ * std::cos(t);
    }

    double Circle::GetDerivativeZ(double t) const {
        (void)t;
        return 0.0;
    }
} // namespace circle
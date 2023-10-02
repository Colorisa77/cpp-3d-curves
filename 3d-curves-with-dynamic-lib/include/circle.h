#pragma once

#include "curve.h"

namespace circle {
    class Circle : public curve::Curve {
    public:
        explicit Circle(curve::CurveType type, double radius);

        curve::Point3D GetPoint(double t) const override;
        curve::Vector3D GetDerivative(double t) const override;
        curve::CurveType GetCurveType() const override;

        double GetRadius() const;

    protected:
        double GetX(double t) const override;
        double GetY(double t) const override;
        double GetZ(double t) const override;

        double GetDerivativeX(double t) const override;
        double GetDerivativeY(double t) const override;
        double GetDerivativeZ(double t) const override;

    private:
        curve::CurveType type_;
        double radius_;
    };
} // namespace circle
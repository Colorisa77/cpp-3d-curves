#pragma once

#include "curve.h"

namespace ellipse {

    class Ellipse : public curve::Curve {
    public:
        explicit Ellipse(double axis_x, double axis_y);

        curve::Point3D GetPoint(double t) const override;
        curve::Vector3D GetDerivative(double t) const override;

        double GetAxisX() const;
        double GetAxisY() const;

    protected:
        double GetX(double t) const override;
        double GetY(double t) const override;
        double GetZ(double t) const override;

        double GetDerivativeX(double t) const override;
        double GetDerivativeY(double t) const override;
        double GetDerivativeZ(double t) const override;

    private:
        double axis_x_;
        double axis_y_;
    };

} // namespace ellipse
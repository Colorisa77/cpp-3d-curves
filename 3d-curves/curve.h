#pragma once

#include "common.h"

namespace curve {
    class Curve {
    public:
        virtual Point3D GetPoint(double t) const = 0;
        virtual Vector3D GetDerivative(double t) const = 0;
        virtual CurveType GetCurveType() const = 0;

    protected:
        virtual double GetX(double t) const = 0;
        virtual double GetY(double t) const = 0;
        virtual double GetZ(double t) const = 0;

        virtual double GetDerivativeX(double t) const = 0;
        virtual double GetDerivativeY(double t) const = 0;
        virtual double GetDerivativeZ(double t) const = 0;
    };
} // namespace curve
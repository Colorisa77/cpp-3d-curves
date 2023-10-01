#pragma once

#include "circle.h"

namespace helix {
    class Helix : public circle::Circle {
    public:
        explicit Helix(double radius, double step);

        double GetStep() const;

    protected:
        double GetZ(double t) const override;

        double GetDerivativeZ(double t) const override;

    private:
        double step_;
    };
} // namespace helix
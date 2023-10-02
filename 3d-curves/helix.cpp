#include "helix.h"

#include <cmath>

namespace helix {
    Helix::Helix(curve::CurveType type, double radius, double step)
    : circle::Circle(type, radius)
    , step_(step) {
        if(radius <= 0.0 || step <= 0.0) {
            throw std::invalid_argument("parameters must be greater than 0");
        }
    }

    double Helix::GetStep() const {
        return step_;
    }

    double Helix::GetZ(double t) const {
        return t * step_ / (2 * M_PI);
    }

    double Helix::GetDerivativeZ(double t) const {
        (void)t;
        return step_ * (2 * M_PI);
    }
} // namespace helix
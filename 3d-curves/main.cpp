#include <iostream>

#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

#include <random>
#include <memory>
#include <deque>
#include <algorithm>
#include <execution>

std::deque<std::unique_ptr<curve::Curve>> PopulatingContainerWithRandomObjects() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);
    std::uniform_real_distribution<> distr_param(1.0, 5000.0);

    std::deque<std::unique_ptr<curve::Curve>> container;
    for (int i = 0; i < 50; ++i) {
        int type = distr(gen);

        switch(type) {
            case 1:
                container.emplace_back(std::make_unique<circle::Circle>(circle::Circle(curve::CurveType::CIRCLE, distr_param(gen))));
                break;
            case 2:
                container.emplace_back(std::make_unique<ellipse::Ellipse>(ellipse::Ellipse(curve::CurveType::ELLIPSE, distr_param(gen), distr_param(gen))));
                break;
            case 3:
                container.emplace_back(std::make_unique<helix::Helix>(helix::Helix(curve::CurveType::HELIX, distr_param(gen), distr_param(gen))));
                break;
            default:
                break;
        }
    }
    return container;
}

void PrintingPointsAndDerivatives(const std::deque<std::unique_ptr<curve::Curve>>& container) {
    for(const auto& curve : container) {
        auto point =  curve->GetPoint(M_PI_4);
        auto derivative = curve->GetDerivative(M_PI_4);
        std::cout << curve->GetCurveType() << "'s point: " << point << ", derivative: " << derivative << std::endl;
    }
}

std::deque<circle::Circle*> PopulatingContainerWithCirclesFromOtherContainer(const std::deque<std::unique_ptr<curve::Curve>>& container) {
    std::deque<circle::Circle*> circles;
    for(const auto& curve : container) {
        if(curve->GetCurveType() == curve::CurveType::CIRCLE) {
            circles.push_back(static_cast<circle::Circle*>(curve.get()));
        }
    }
    return circles;
}

void SortByRadius(std::deque<circle::Circle*>& container) {
    std::sort(container.begin(), container.end(), [](circle::Circle* lhs, circle::Circle* rhs) {
        return lhs->GetRadius() < rhs->GetRadius();
    });
}

double ComputeTheTotalSumOfRadii(const std::deque<circle::Circle*>& container) {

    double total_sum = 0.0;
    std::for_each(std::execution::par, container.begin(), container.end(), [&total_sum](circle::Circle* circle) {
        return total_sum += circle->GetRadius();
    });

    return total_sum;
}

void MakeTasks() {
    auto container = PopulatingContainerWithRandomObjects();

    PrintingPointsAndDerivatives(container);

    auto second_container = PopulatingContainerWithCirclesFromOtherContainer(container);
    SortByRadius(second_container);

    std::cout << "\ntotal sum of radii for all circles: " << ComputeTheTotalSumOfRadii(second_container) << std::endl;
}

int main() {
    MakeTasks();
    return 0;
}
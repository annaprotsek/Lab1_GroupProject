#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main()
{
    auto data = std::make_shared<const InputData>(InputData{
        [](double x) { return (x - 2.0) * (x - 2.0) + 1.0; }, // f(x) = (x-2)^2 + 1, мінімум у x=2
        0.0,   // a
        5.0,   // b
        1e-5   // eps
    });

    auto resultB = calculateB(data);
    auto [xB, fxB, iterB, methodB] = *resultB;

    std::cout << "Student B (" << methodB << "): x = " << xB
               << ", f(x) = " << fxB << ", iterations = " << iterB << "\n";

    return 0;
}
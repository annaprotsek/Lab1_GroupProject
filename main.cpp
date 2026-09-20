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

    auto resultA = calculateA(data);
    auto [xA, fxA, iterA, methodA] = *resultA;

    std::cout << "Student A (" << methodA << "): x = " << xA
               << ", f(x) = " << fxA << ", iterations = " << iterA << "\n";

    return 0;
}
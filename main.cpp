#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main()
{
    auto data = std::make_shared<const InputData>(InputData{
        [](double x) { return (x - 2.0) * (x - 2.0) + 1.0; },
        0.0,
        5.0,
        1e-5
    });

    auto resultA = calculateA(data);
    auto [xA, fxA, iterA, methodA] = *resultA;

    std::cout << "Student A (" << methodA << "): x = " << xA
               << ", f(x) = " << fxA << ", iterations = " << iterA << "\n";

    auto resultB = calculateB(data);
    auto [xB, fxB, iterB, methodB] = *resultB;

    std::cout << "Student B (" << methodB << "): x = " << xB
               << ", f(x) = " << fxB << ", iterations = " << iterB << "\n";

    return 0;
}
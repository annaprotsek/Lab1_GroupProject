#pragma once
#include <functional>
#include <string>

struct InputData
{
    std::function<double(double)> f; // досліджувана функція
    double a;                        // ліва межа інтервалу
    double b;                        // права межа інтервалу
    double eps;                      // точність
};

struct Result
{
    double x;            // координата екстремуму
    double fx;           // значення функції в екстремумі
    int iterations;      // кількість ітерацій
    std::string method;  // назва методу
};
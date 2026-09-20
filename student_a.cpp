#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data)
{
    double a = data->a;
    double b = data->b;
    const double eps = data->eps;

    const double phi = (std::sqrt(5.0) - 1.0) / 2.0; // золотий переріз ≈ 0.618

    double x1 = b - phi * (b - a);
    double x2 = a + phi * (b - a);
    double f1 = data->f(x1);
    double f2 = data->f(x2);

    int iterations = 0;

    while ((b - a) > eps)
    {
        if (f1 < f2)
        {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - phi * (b - a);
            f1 = data->f(x1);
        }
        else
        {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + phi * (b - a);
            f2 = data->f(x2);
        }

        ++iterations;
    }

    double x = (a + b) / 2.0;
    double fx = data->f(x);

    return std::make_unique<Result>(Result{x, fx, iterations, "golden-section"});
}
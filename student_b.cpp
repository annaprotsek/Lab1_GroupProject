#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data)
{
    double a = data->a;
    double b = data->b;
    const double eps = data->eps;
    const double delta = eps / 3.0; // зсув від середини, має бути меншим за eps/2

    int iterations = 0;

    while ((b - a) > eps)
    {
        double mid = (a + b) / 2.0;
        double x1 = mid - delta;
        double x2 = mid + delta;

        if (data->f(x1) < data->f(x2))
        {
            b = x2;
        }
        else
        {
            a = x1;
        }

        ++iterations;
    }

    double x = (a + b) / 2.0;
    double fx = data->f(x);

    return std::make_unique<Result>(Result{x, fx, iterations, "dichotomy"});
}
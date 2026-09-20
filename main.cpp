#include <iostream>
#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main()
{
    std::cout << "Lab1_GroupProject: extremum search\n";
    return 0;
}
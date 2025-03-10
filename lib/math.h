#pragma once
#include "check.h"
#include "utils.h"
#include "constant.h"

namespace Math
{
    double getDimension(const std::string &message)
    {
        double dimension;
        bool validInput = false;
        do
        {
            std::cout << message;
            if (std::cin >> dimension)
            {
                if (Check::isValidDimension(dimension))
                    validInput = true;
                else
                    std::cout << "Error: Dimension must be between " << Constant::MIN_LENGTH << " and " << Constant::MAX_LENGTH << " units.\n";
            }
            else
            {
                Utils::clearInputBuffer();
                std::cout << "Error: Invalid input. Please enter a valid number.\n";
            }
        } while (!validInput);
        return dimension;
    }
}

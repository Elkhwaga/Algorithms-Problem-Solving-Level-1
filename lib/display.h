#pragma once
#include <iostream>
#include <iomanip>

namespace Display
{
    void displayWelcomeMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    void displayGoodbyeMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }
}
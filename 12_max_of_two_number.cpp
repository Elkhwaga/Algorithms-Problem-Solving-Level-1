#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0

    - Program to find the maximum of two numbers
    - Enhanced error handling

    {
        - #include "input.h" -> Input::readNumberCustom
        - #include "input.h" -> Input::readYesNo
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Do you want to allow negative numbers?
        -- Enter 1 for Yes, 0 for No: 1
        -- Enter the first number: 10
        -- Enter the second number: 20

    -----------------------------------------------------------------
    - Example Output:
        -- First number: 10
        -- Second number: 20
        -- Maximum value: 20

    -----------------------------------------------------------------
    - Example Input:
        -- Do you want to allow negative numbers?
        -- Enter 1 for Yes, 0 for No: 0
        -- Enter the first number: 10
        -- Enter the second number: 20

    -----------------------------------------------------------------
    - Example Output:
        -- First number: 10
        -- Second number: 20
        -- Maximum value: 20

    -- Goodbye!
*/

/**
 * @brief Function to find the maximum of two numbers
 * @param num1 First number
 * @param num2 Second number
 * @return float Maximum of the two numbers
 */

float max(float num1, float num2)
{
    return (num1 > num2) ? num1 : num2;
}

/**
 * @brief Main application logic with enhanced error handling
 */
void PrintResult()
{
    try
    {
        Input input;

        bool allowNegative = input.readYesNo("Do you want to allow negative numbers?\nEnter 1 for Yes, 0 for No: ");

        float num1 = input.readNumberCustom("Enter the first number:", allowNegative);
        float num2 = input.readNumberCustom("Enter the second number:", allowNegative);

        std::cout << "\nResults:" << std::endl;
        std::cout << "First number: " << num1 << std::endl;
        std::cout << "Second number: " << num2 << std::endl;
        std::cout << "Maximum value: " << max(num1, num2) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "\nFatal Error: " << e.what() << std::endl;
        std::cerr << "Program terminated due to too many invalid inputs." << std::endl;
    }
}

int main()
{
    Display::displayWelcomeMessage(
        "Welcome to the Maximum Number Calculator\nThis program finds the maximum of two numbers.");

    PrintResult();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
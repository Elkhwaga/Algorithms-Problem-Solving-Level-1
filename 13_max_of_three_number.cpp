#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0

    - Program to find the maximum of three numbers
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
        -- Enter the first number: 10
        -- Enter the second number: 20
        -- Enter the third number: 30

    -----------------------------------------------------------------
    - Example Output:
        -- First number:  10.00
        -- Second number: 20.00
        -- Third number:  30.00
        -- Maximum number: 30.00

    -- Goodbye!
*/

/**
 * @brief Determines the maximum of three integer numbers.
 *
 * This function takes three integer arguments and returns the largest
 * of the three. It compares the numbers using conditional statements
 * to determine which one is the greatest.
 *
 * @param num1 The first integer number.
 * @param num2 The second integer number.
 * @param num3 The third integer number.
 * @return The largest of the three integer numbers as a float.
 */
float maxOfThreeNumber(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
    {
        return num1;
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        return num2;
    }
    else
    {
        return num3;
    }
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
        float num3 = input.readNumberCustom("Enter the third number:", allowNegative);

        std::cout << "\nResults:" << std::endl;
        std::cout << "First number: " << num1 << std::endl;
        std::cout << "Second number: " << num2 << std::endl;
        std::cout << "Third number: " << num2 << std::endl;
        std::cout << "Maximum value: " << maxOfThreeNumber(num1, num2, num3) << std::endl;
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
#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter three numbers and then prints their sum.
        -- The program should use a function to read the numbers and a function to print the sum.

    - #include "input.h" -> Input::readPositiveFloatNumber

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
        -- First Number:  10.00
        -- Second Number: 20.00
        -- Third Number:  30.00
        -- Sum:           60.00

    -- Goodbye!
*/

float sumThreeNumbers(float num1, float num2, float num3)
{
    return num1 + num2 + num3;
}

void printResult(float num1, float num2, float num3)
{
    float sum = sumThreeNumbers(num1, num2, num3);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n|----------------------------|";
    std::cout << "\n|      FINAL RESULTS         |";
    std::cout << "\n|----------------------------|";

    std::cout << "\n| First Number:  " << std::setw(11) << num1 << " |";
    std::cout << "\n| Second Number: " << std::setw(11) << num2 << " |";
    std::cout << "\n| Third Number:  " << std::setw(11) << num3 << " |";
    std::cout << "\n|----------------------------|";

    std::cout << "\n| Sum:           " << std::setw(11) << sum << " |";
    std::cout << "\n|----------------------------|" << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Sum of 3 Numbers Program!");

    float num1 = Input::readPositiveFloatNumber("Please enter first number: "),
          num2 = Input::readPositiveFloatNumber("Please enter second number: "),
          num3 = Input::readPositiveFloatNumber("Please enter last number: ");

    printResult(num1, num2, num3);

    Display::displayGoodbyeMessage("Thank you for using the Sum of 3 Numbers Program!");

    return 0;
}
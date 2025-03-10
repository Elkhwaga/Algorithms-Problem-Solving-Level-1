#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number and then prints the factorial of that number.
        -- The program should use a function to read the number and a function to calculate the factorial.

    - #include "./lib/input.h" -> Input::readPositiveNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 5

    -----------------------------------------------------------------
    - Example Output:
        -- The factorial of 5 is: 120

    -- Thank you for using the Factorial Calculator!
*/

int factorial(int number)
{
    int result = 1;
    for (int i = number; i >= 1; i--)
    {
        result *= i;
    }
    return result;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Factorial Calculator!");

    int number = Input::readPositiveNumber("Enter a number: ");
    int result = factorial(number);
    std::cout << "The factorial of " << number << " is: " << result << std::endl;

    Display::displayGoodbyeMessage("Thank you for using the Factorial Calculator!");

    return 0;
}
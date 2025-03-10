#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0

    - Write a program that prompts the user to enter a number and a power and then prints the power of that number for that power.
        -- The program should use a function to read the number and a function to calculate the power.

    - #include "./lib/input.h" -> Input::readPositiveNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 3
        -- Enter a power: 2

    -----------------------------------------------------------------
    - Example Output:
        -- 3^2 = 9

    -- Goodbye!
*/

int powerOf(int number, int power)
{
    int result = 1;
    if (power == 0)
    {
        return 1;
    }

    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

void printResult(int number, int power)
{
    std::cout << number << "^" << power << " = " << powerOf(number, power) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Power Calculator");

    int number = Input::readPositiveNumber("Enter a number: ");
    int power = Input::readPositiveNumber("Enter a power: ");
    printResult(number, power);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
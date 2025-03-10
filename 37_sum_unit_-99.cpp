#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0

    - Write a program that prompts the user to enter numbers until -99 is entered.
        --The program should calculate and display the sum of the entered numbers.

    - #include "./lib/input.h" -> Input::readNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number (enter -99 to stop): 10
        -- Enter a number (enter -99 to stop): 20
        -- Enter a number (enter -99 to stop): 30
        -- Enter a number (enter -99 to stop): -99
    -----------------------------------------------------------------
    - Example Output:
        -- This program calculates the sum of numbers entered by the user.
        -- Enter -99 to stop entering numbers and display the sum.
        -- The sum is: 60

    -- Thank you for using the Sum Calculator with -99!
*/

/**
 * Calculates the sum of numbers entered by the user until -99 is entered.
 * @return The sum of the entered numbers.
 */
float calculateSum()
{
    float sum = 0;
    float number;

    while (true)
    {
        number = Input::readNumber("Enter a number (enter -99 to stop): ");
        if (number == -99)
        {
            std::cout << "Stopping input. Calculating the sum..." << std::endl;
            break;
        }
        sum += number;
    }

    return sum;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Sum Calculator with -99!\nThis program that prompts the user to enter numbers until -99 is entered");

    std::cout << "This program calculates the sum of numbers entered by the user." << std::endl;
    std::cout << "Enter -99 to stop entering numbers and display the sum." << std::endl;

    float sum = calculateSum();
    std::cout << "The sum is: " << sum << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
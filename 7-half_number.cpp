#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a positive floating-point number.
        -- The program should calculate the half of the number and display the result.

    {
        - #include "input.h" -> Input::readPositiveFloatNumber
        - #include "check.h" -> Check::isContinue
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a positive floating-point number: 5.5

    -----------------------------------------------------------------
    - Example Output:
        -- Half of 5.5 is 2.75
        -- Do you want to continue? (Y/N): Y

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a positive floating-point number: -5.5

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a positive floating-point number.
        -- Do you want to continue? (Y/N): N

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a positive floating-point number: 0

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a positive floating-point number.
        -- Do you want to continue? (Y/N): N

    -- Goodbye!
*/

float halfNumber(float number)
{
    return number / 2;
}

void printResult(float number)
{
    std::cout << "\nHalf of " << number << " is " << halfNumber(number) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Number Halving Program!");

    char choice;
    do
    {
        printResult(Input::readPositiveFloatNumber("Enter a positive floating-point number: "));

        choice = Input::readChoice("Do you want to continue? (Y/N): ");
    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
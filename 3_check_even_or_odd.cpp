#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


   - Write a program that prompts the user to enter a number and checks if it is even or odd.
        -- The program should display a message indicating whether the number is even or odd.

    {
        - #include "input.h" -> Input::readPositiveNumber
        - #include "input.h" -> Input::readChoice
    }
    {
        - #include "display.h" -> Display::DisplayResult
        - #include "display.h" -> Display::DisplayWelcomeMessage
    }
    {
        - #include "check.h" -> Check::isContinue
        - #include "check.h" -> Check::isEven
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 5

    -----------------------------------------------------------------
    - Example Output:
        -- Enter a number: 5
        -- The number 5 is odd.
        -- Do you want to continue? (Y/N): Y

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: -5

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a positive number.
        -- Do you want to continue? (Y/N): N

    -- Goodbye!
*/

void DisplayResult(int number)
{
    (Check::isEven(number))
        ? std::cout << "The number " << number << " is even." << std::endl
        : std::cout << "The number " << number << " is odd." << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Even/Odd Number Checker!");

    char choice;
    do
    {
        DisplayResult(Input::readPositiveNumber("Enter a number: "));

        choice = Input::readChoice("Do you want to continue? (Y/N): ");

    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
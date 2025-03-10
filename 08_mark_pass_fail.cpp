#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a mark and checks if it is a pass or fail.
        -- The program should display a message indicating whether the mark is a pass or fail.

    {
        - #include "input.h" -> Input::readNumberInRange
        - #include "input.h" -> Input::readChoice
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }
    {
        - #include "check.h" -> Check::checkStatus
        - #include "check.h" -> Check::isContinue
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a mark between 0 and 100: 50

    -----------------------------------------------------------------
    - Example Output:
        -- Pass
        -- Do you want to continue? (Y/N): Y

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a mark between 0 and 100: 101

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a number between 0 and 100.
        -- Do you want to continue? (Y/N): N

    -- Goodbye!
*/

void printResult(float mark)
{
    (Check::checkStatus(mark) == Enums::Status::PASS)
        ? std::cout << "Pass" << std::endl
        : std::cout << "Fail" << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Mark Pass/Fail Program!");

    char choice;
    do
    {
        printResult(Input::readNumberInRange("Enter a mark between 0 and 100: ", 0, 100));

        choice = Input::readChoice("Do you want to continue? (Y/N): ");

    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
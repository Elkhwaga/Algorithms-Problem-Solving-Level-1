#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number and checks if it is a prime number.
        -- The program should display a message indicating whether the number is a prime number or not.

    - #include "input.h" -> Input::readPositiveNumber
    - #include "check.h" -> Check::isPrimeOrNot
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 7

    -----------------------------------------------------------------
    - Example Output:
        -- 7 is a prime number.

    -- Thank you for using the Prime Number Checker!
*/

void printResult(int number)
{
    switch (Check::isPrimeOrNot(number))
    {
    case Enums::PrimeOrNot::PRIME:
        std::cout << number << " is a prime number." << std::endl;
        break;
    case Enums::PrimeOrNot::NOT_PRIME:
        std::cout << number << " is not a prime number." << std::endl;
        break;
    }
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Prime Number Checker");

    int number = Input::readPositiveNumber("Enter a number: ");
    printResult(number);

    Display::displayGoodbyeMessage("Thank you for using the Prime Number Checker!");

    return 0;
}
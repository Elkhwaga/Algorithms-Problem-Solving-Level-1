#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number and then prints the power of 2, 3, and 4 for that number.
        -- The program should use a function to read the number and a function to calculate the powers.

    {
        - #include "./lib/input.h" -> Input::readPositiveNumber
        - #include "./lib/input.h" -> Input::readNumberAndValidate
    }
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 3
        -- Menu:
        -- Power Calculator
        -- 1. All powers
        -- 2. Power of 2
        -- 3. Power of 3
        -- 4. Power of 4
        -- 5. Exit
        -- Enter a number: 3

    -----------------------------------------------------------------
    - Example Output:
        -- 2^3 = 8
        -- 3^3 = 27
        -- 4^3 = 64

    -- Goodbye!
*/

enum Choice
{
    ALL = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    EXIT = 5
};

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

void showMenu()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. All powers" << std::endl;
    std::cout << "2. Power of 2" << std::endl;
    std::cout << "3. Power of 3" << std::endl;
    std::cout << "4. Power of 4" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void printResult(Choice choice, int number)
{
    switch (choice)
    {
    case ALL:
        std::cout << "2^" << number << " = " << powerOf(2, number) << std::endl;
        std::cout << "3^" << number << " = " << powerOf(3, number) << std::endl;
        std::cout << "4^" << number << " = " << powerOf(4, number) << std::endl;
        break;

    case TWO:
        std::cout << "2^" << number << " = " << powerOf(2, number) << std::endl;
        break;

    case THREE:
        std::cout << "3^" << number << " = " << powerOf(3, number) << std::endl;
        break;

    case FOUR:
        std::cout << "4^" << number << " = " << powerOf(4, number) << std::endl;
        break;
    }
}

int main()
{
    Display::displayWelcomeMessage("Power Calculator");

    int number;
    short choice;

    do
    {
        number = Input::readPositiveNumber("Enter a number: ");
        showMenu();
        choice = Input::readNumberAndValidate("Enter your choice: ", 1, 5);
        printResult(static_cast<Choice>(choice), number);
    } while (choice != EXIT);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
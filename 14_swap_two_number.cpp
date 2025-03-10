#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter two numbers and then swaps them.
        -- The program should use a function to read the numbers and a function to swap them.

    - #include "./lib/input.h" -> Input::readNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the first number: 10
        -- Enter the second number: 20

    -----------------------------------------------------------------
    - Example Output:
        -- First number: 20
        -- Second number: 10

    -- Thank you for using the Program that Swaps Two Numbers!
*/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printNumbers(int number, int number2)
{
    std::cout << number << std::endl;
    std::cout << number2 << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Swaps Two Numbers!");

    int number = Input::readNumber("Enter the first number: ");
    int number2 = Input::readNumber("Enter the second number: ");
    printNumbers(number, number2);

    swap(number, number2);

    printNumbers(number, number2);

    Display::displayGoodbyeMessage("Thank you for using the Program that Swaps Two Numbers!");

    return 0;
}
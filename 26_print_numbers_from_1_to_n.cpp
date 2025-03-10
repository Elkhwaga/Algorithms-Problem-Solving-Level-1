#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number between 1 and 50 and then prints all numbers from 1 to that number.
    -- The program should use a function to read the number and a function to print the numbers.

    - #include "./lib/input.h" -> Input::readNumberAndValidate
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number between 1 and 50: 10

    -----------------------------------------------------------------
    - Example Output:
        -- The valid number is: 10

    -- Thank you for using the Program that Prints Numbers from 1 to N!
*/

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 50;

void printNumbers(int number)
{
    for (short i = 1; i <= number; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Numbers from 1 to N!");

    int number = Input::readNumberAndValidate("Enter a number between 1 and 50: ", MIN_NUMBER, MAX_NUMBER);

    if (number == -1)
    {
        std::cout << "Failed to get a valid number.\n";
        return -1;
    }

    std::cout << "The valid number is: " << number << std::endl;
    printNumbers(number);

    Display::displayGoodbyeMessage("Thank you for using the Program that Prints Numbers from 1 to N!");

    return 0;
}
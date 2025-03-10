#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number and then prints the sum of all odd numbers from 1 to that number.
        -- The program should use a function to read the number and a function to calculate the sum.

    - #include "./lib/input.h" -> Input::readPositiveNumber
    - #include "./lib/check.h" -> Check::GetNumberType
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 10

    -----------------------------------------------------------------
    - Example Output:
        -- The sum of odd numbers from 1 to 10 is: 25

    -- Goodbye!
*/

int GetSumOfOddNumbers(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i++)
    {
        if (Check::GetNumberType(i) == Enums::OddOrEven::ODD)
            sum += i;
    }
    return sum;
}

int main()
{
    Display::displayWelcomeMessage("Sum of odd numbers from 1 to n");

    int number = Input::readPositiveNumber("Enter a number: ");
    int sum = GetSumOfOddNumbers(number);
    std::cout << "The sum of odd numbers from 1 to " << number << " is: " << sum << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
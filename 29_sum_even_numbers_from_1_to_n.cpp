#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number and then prints the sum of all even numbers from 1 to that number.
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
        -- The sum of even numbers from 1 to 10 is: 30

    -- Goodbye!
*/

int GetSumOfEvenNumbers(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i++)
    {
        if (Check::GetNumberType(i) == Enums::OddOrEven::EVEN)
            sum += i;
    }
    return sum;
}

int main()
{
    Display::displayWelcomeMessage("Sum of even numbers from 1 to n");

    int number = Input::readPositiveNumber("Enter a number: ");
    int sum = GetSumOfEvenNumbers(number);
    std::cout << "The sum of even numbers from 1 to " << number << " is: " << sum << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
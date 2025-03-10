#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter three numbers and then prints the average of those numbers.
        -- The program should use a function to read the numbers and a function to calculate the average.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the first mark: 10
        -- Enter the second mark: 20
        -- Enter the third mark: 30

    -----------------------------------------------------------------
    - Example Output:
        -- Average: 20

    -- Goodbye!
*/

float calculateAverage(float mark1, float mark2, float mark3)
{
    return (mark1 + mark2 + mark3) / 3;
}

int main()
{
    Display::displayWelcomeMessage("Average Calculator");

    float mark1 = Input::readPositiveFloatNumber("Enter the first mark: ");
    float mark2 = Input::readPositiveFloatNumber("Enter the second mark: ");
    float mark3 = Input::readPositiveFloatNumber("Enter the third mark: ");

    std::cout << "\nAverage: " << calculateAverage(mark1, mark2, mark3) << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number between 0 and 100 and then prints the grade for that number.
        -- The program should use a function to read the number and a function to print the grade.

    - #include "./lib/input.h" -> Input::readNumberAndValidate
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number between 0 and 100: 85

    -----------------------------------------------------------------
    - Example Output:
        -- Your grade is: B

    -- Goodbye!
*/

void printGrade(float grade)
{
    if (grade >= 90 && grade <= 100)
        std::cout << "A";
    else if (grade >= 80 && grade < 90)
        std::cout << "B";
    else if (grade >= 70 && grade < 80)
        std::cout << "C";
    else if (grade >= 60 && grade < 70)
        std::cout << "D";
    else if (grade >= 50 && grade < 60)
        std::cout << "E";
    else
        std::cout << "F";
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Grade Calculator!");

    printGrade(Input::readNumberAndValidate("Enter a number between 0 and 100: ", 0, 100));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
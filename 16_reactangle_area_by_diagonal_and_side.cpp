#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the length and width of a rectangle and then prints the area of the rectangle.
        -- The program should use a function to read the dimensions and a function to calculate the area.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the length of the rectangle: 5
        -- Enter the width of the rectangle: 40

    -----------------------------------------------------------------
    - Example Output:
        -- Rectangle Area = 198.431

    -- Goodbye!
*/

float rectangleAreaBySideAndDiagonal(float side, float diagonal)
{
    float Area = side * sqrt(pow(diagonal, 2) - pow(side, 2));

    return Area;
}

void printResult(float area)
{
    std::cout << "\nRectangle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Rectangle Area Calculator!");

    float side = Input::readPositiveFloatNumber("Please enter rectangle side: ");
    float diagonal = Input::readPositiveFloatNumber("Please enter rectangle diagonal: ");

    printResult(rectangleAreaBySideAndDiagonal(side, diagonal));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
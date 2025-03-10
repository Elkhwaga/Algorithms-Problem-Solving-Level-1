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
        -- Enter the triangle base: 10
        -- Enter the triangle height: 8

    -----------------------------------------------------------------
    - Example Output:
        -- Triangle Area = 40

    -- Goodbye!
*/

float triangleArea(float base, float height)
{
    float Area = (base * height) / 2;

    return Area;
}

void printResult(float area)
{
    std::cout << "\nTriangle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Triangle Area Calculator!");

    float base = Input::readPositiveFloatNumber("Please enter triangle base: ");
    float height = Input::readPositiveFloatNumber("Please enter triangle height: ");

    printResult(triangleArea(base, height));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
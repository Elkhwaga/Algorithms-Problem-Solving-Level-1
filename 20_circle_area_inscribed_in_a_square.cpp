#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the side of a square and then prints the area of the circle that is inscribed in the square.
        -- The program should use a function to read the side and a function to calculate the area.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Please enter side of the square: 10

    -----------------------------------------------------------------
    - Example Output:
        -- Circle Area = 78.5398

    -- Goodbye!
*/

float circleAreaByDiameter(float radius)
{
    const float PI = 3.141592653589793238;
    float Area = (PI * pow(radius, 2)) / 4;

    return Area;
}

void printResult(float area)
{
    std::cout << "\nCircle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Circle Area Calculator!");

    float side = Input::readPositiveFloatNumber("Please enter side of the square: ");

    printResult(circleAreaByDiameter(side));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
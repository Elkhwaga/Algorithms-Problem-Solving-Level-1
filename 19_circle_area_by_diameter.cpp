#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the radius of a circle and then prints the area of the circle.
        -- The program should use a function to read the radius and a function to calculate the area.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the radius of the circle: 10

    -----------------------------------------------------------------
    - Example Output:
        -- Circle Area = 78.5398

    -- Goodbye!
*/

float circleAreaByDiameter(float radius)
{
    const float PI = 3.141592653589793238;
    float Area = (pow(radius, 2) * PI) / 4;

    return Area;
}

void printResult(float area)
{
    std::cout << "\nCircle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Circle Area Calculator!");

    float radius = Input::readPositiveFloatNumber("Please enter circle radius: ");

    printResult(circleAreaByDiameter(radius));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
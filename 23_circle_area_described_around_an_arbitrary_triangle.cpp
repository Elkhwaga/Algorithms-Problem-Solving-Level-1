#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the sides of an arbitrary triangle and then prints the area of the circle that is described around the triangle.
        -- The program should use a function to read the sides and a function to calculate the area.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Please enter triangle side A: 5
        -- Please enter triangle side B: 6
        -- Please enter triangle side C: 7

    -----------------------------------------------------------------
    - Example Output:
        -- Circle Area = 40.088

    -- Goodbye!
*/

float circleAreaByArbitraryTriangle(float A, float B, float C)
{
    const float PI = 3.141592653589793238;
    float P = (A + B + C) / 2;
    float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
    float Area = PI * pow(T, 2);

    return Area;
}

void printResult(float area)
{
    std::cout << "\nCircle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Circle Area Calculator!");

    float A = Input::readPositiveFloatNumber("Please enter triangle side A: ");
    float B = Input::readPositiveFloatNumber("Please enter triangle side B: ");
    float C = Input::readPositiveFloatNumber("Please enter triangle side C: ");

    printResult(circleAreaByArbitraryTriangle(A, B, C));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
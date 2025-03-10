#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the sides of an isosceles triangle and then prints the area of the circle that is inscribed in the triangle.
        -- The program should use a function to read the sides and a function to calculate the area.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Please enter triangle side A: 10
        -- Please enter triangle base B: 15

    -----------------------------------------------------------------
    - Example Output:
        -- Circle Area = 25.2449

    -- Goodbye!
*/

float circleAreaByIsoscelesTriangle(float A, float B)
{
    const float PI = 3.141592653589793238;
    float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

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
    float B = Input::readPositiveFloatNumber("Please enter triangle base B: ");

    printResult(circleAreaByIsoscelesTriangle(A, B));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
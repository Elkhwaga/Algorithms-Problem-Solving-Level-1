#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the circumference of a circle and then prints the area of the circle.
        -- The program should use a function to read the circumference and a function to calculate the area.


    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Please enter circumference: 20

    -----------------------------------------------------------------
    - Example Output:
        -- Circle Area = 31.831

    -- Goodbye!
*/

float circleAreaByCircumference(float L)
{
    const float PI = 3.141592653589793238;
    float Area = pow(L, 2) / (4 * PI);

    return Area;
}

void printResult(float area)
{
    std::cout << "\nCircle Area = " << area << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Circle Area Calculator!");

    float L = Input::readPositiveFloatNumber("Please enter circumference: ");

    printResult(circleAreaByCircumference(L));

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
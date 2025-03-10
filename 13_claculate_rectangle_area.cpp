#include "./lib/math.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the length and width of a rectangle and then prints the area of the rectangle.
        -- The program should use a function to read the dimensions and a function to calculate the area.

    {
        - #include "./lib/math.h" -> Math::getDimension
        - #include "./lib/math.h" -> Math::getDimension
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the length of the rectangle: 5
        -- Enter the width of the rectangle: 3

    -----------------------------------------------------------------
    - Example Output:
        -- Rectangle Details:
        -- ==================
        -- Length: 5.00 units
        -- Width: 3 units
        -- Area: 15 square units

    -- Goodbye!
*/

/**
 * @brief Calculates the area of a rectangle
 * @param length The length of the rectangle
 * @param width The width of the rectangle
 * @return double The area of the rectangle
 */
double calculateArea(double length, double width)
{
    return length * width;
}

/**
 * @brief Displays the rectangle's information
 * @param length The length of the rectangle
 * @param width The width of the rectangle
 * @param area The area of the rectangle
 * @param perimeter The perimeter of the rectangle
 */
void displayResults(double length, double width, double area)
{
    std::cout << "\nRectangle Details:\n";
    std::cout << "==================\n";
    std::cout << "Length: " << std::fixed << std::setprecision(2) << length << " units\n";
    std::cout << "Width: " << width << " units\n";
    std::cout << "Area: " << area << " square units\n";
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Rectangle Area Calculator!");

    // Get dimensions from user
    double length = Math::getDimension("Enter the length of the rectangle: ");
    double width = Math::getDimension("Enter the width of the rectangle: ");

    // Calculate area and perimeter
    double area = calculateArea(length, width);

    // Display results
    displayResults(length, width, area);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
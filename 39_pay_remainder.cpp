#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the total pay and total cash.
        -- The program should calculate the remainder and display it along with the total pay and total cash.

    - #include "input.h" -> Input::readPositiveFloatNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter total pay: 100
        -- Enter total cash: 50

    -----------------------------------------------------------------
    - Example Output:
        -- Total pay: 100
        -- Total cash: 50
        -- ****************************
        -- Remainder: 50

    -- Thank you for using the Pay Remainder Calculator!
*/

float calculateRemainder(float totalCash, float totalPay)
{
    return totalCash - totalPay;
}

void printResult(float totalPay, float totalCash)
{
    std::cout << "Total pay: " << totalPay << std::endl;
    std::cout << "Total cash: " << totalCash << std::endl;
    std::cout << "****************************\n";
    std::cout << "Remainder: " << calculateRemainder(totalCash, totalPay) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Pay Remainder Calculator");

    float totalPay = Input::readPositiveFloatNumber("Enter total pay: ");
    float totalCash = Input::readPositiveFloatNumber("Enter total cash: ");
    printResult(totalPay, totalCash);

    Display::displayGoodbyeMessage("Thank you for using the Pay Remainder Calculator!");

    return 0;
}
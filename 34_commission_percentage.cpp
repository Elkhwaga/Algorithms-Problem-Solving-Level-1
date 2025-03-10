#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the total sales for a month and then prints the commission percentage and commission amount for that month.
        -- The program should use a function to read the total sales and a function to calculate the commission percentage and commission amount.

        - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the total sales for the month: 100000

    -----------------------------------------------------------------
    - Example Output:
        -- Total sales: 100000
        -- Commission percentage: 0.05
        -- Commission amount: 5000

    -- Thank you for using the Program that Calculates Commission Percentage and Commission Amount!
*/

float CommissionPercentage(float totalSales)
{
    float commissionPercentage;
    if (totalSales >= 50000 && totalSales <= 100000)
    {
        commissionPercentage = 0.05;
    }
    else if (totalSales >= 100000 && totalSales <= 500000)
    {
        commissionPercentage = 0.03;
    }
    else if (totalSales >= 500000 && totalSales <= 1000000)
    {
        commissionPercentage = 0.02;
    }
    else if (totalSales >= 1000000)
    {
        commissionPercentage = 0.01;
    }
    else
    {
        commissionPercentage = 0;
    }
    return commissionPercentage;
}

float getCommissionAmount(float totalSales)
{
    return totalSales * CommissionPercentage(totalSales);
}

void printResult(float totalSales)
{
    std::cout << "Total sales: " << totalSales << std::endl;
    float commissionPercentage = CommissionPercentage(totalSales);
    std::cout << "Commission percentage: " << commissionPercentage << std::endl;
    std::cout << "Commission amount: " << getCommissionAmount(totalSales) << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Commission Percentage Calculator");

    float totalSales = Input::readPositiveFloatNumber("Enter total sales: ");
    printResult(totalSales);

    Display::displayGoodbyeMessage("Thank you for using the Program that Calculates Commission Percentage and Commission Amount!");

    return 0;
}
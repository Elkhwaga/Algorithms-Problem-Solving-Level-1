#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the total bill amount and then calculates and displays the service fee, sales tax, and total amount.
        -- The service fee is 10% of the total bill amount.
        -- The sales tax is 16% of the total bill amount.

    - #include "input.h" -> Input::readPositiveFloatNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the total bill amount: 100

    -----------------------------------------------------------------
    - Example Output:
        -- Service fee: 10.00
        -- Sales tax: 16.00
        -- Total amount: 127.60

    -- Thank you for using the Service Fee and Sales Tax Calculator!
*/

const float SERVICE_FEE = 0.1;
const float SALES_TAX = 0.16;

float calculateServiceFee(float amount)
{
    return amount * SERVICE_FEE;
}

float calculateSalesTax(float amount)
{
    return amount * SALES_TAX;
}

float calculateTotalAmount(float amount)
{
    float serviceFee = calculateServiceFee(amount);
    float salesTax = calculateSalesTax(amount + serviceFee);
    return amount + serviceFee + salesTax;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Service Fee and Sales Tax Calculator");

    float amount = Input::readPositiveFloatNumber("Enter the total bill amount: ");
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Service fee: " << calculateServiceFee(amount) << std::endl;
    std::cout << "Sales tax: " << calculateSalesTax(amount) << std::endl;
    std::cout << "Total amount: " << calculateTotalAmount(amount) << std::endl;

    Display::displayGoodbyeMessage("Thank you for using the Service Fee and Sales Tax Calculator!");
    return 0;
}
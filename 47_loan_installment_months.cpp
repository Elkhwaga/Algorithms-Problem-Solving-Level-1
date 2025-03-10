#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the loan amount and monthly payment.
        -- The program should calculate the number of months it will take to repay the loan.
        -- The program should display the loan amount, monthly payment, and number of months to repay the loan.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the loan amount: 1000
        -- Enter the monthly payment: 100

    -----------------------------------------------------------------
    - Example Output:
        -- Loan Amount: 1000
        -- Monthly Payment: 100
        -- Months to Repay: 10

    -- Thank you for using the Loan Calculator!
*/

struct Loan
{
    float loanAmount;
    float monthlyPayment;

    Loan()
    {
        this->loanAmount = Input::readPositiveFloatNumber("Enter the loan amount: ");
        this->monthlyPayment = Input::readPositiveFloatNumber("Enter the monthly payment: ");
    }

    float calculateMonthsToRepay()
    {
        if (this->monthlyPayment == 0)
        {
            std::cout << "Monthly payment cannot be zero.";
            return;
        }
        return this->loanAmount / this->monthlyPayment;
    }

    void display()
    {
        std::cout << "Loan Amount: " << this->loanAmount << std::endl;
        std::cout << "Monthly Payment: " << this->monthlyPayment << std::endl;
        std::cout << "Months to Repay: " << this->calculateMonthsToRepay() << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Loan Calculator");

    Loan loan;
    loan.display();

    Display::displayGoodbyeMessage("Thank you for using the Loan Calculator!");

    return 0;
}
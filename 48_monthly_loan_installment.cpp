#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the loan amount and the number of months to repay the loan.
        -- The program should calculate the monthly payment amount and display it to the user.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the loan amount: 1000
        -- Enter the number of months to repay: 12

    -----------------------------------------------------------------
    - Example Output:
        -- Loan Amount: 1000
        -- Months to Repay: 12
        -- Monthly Payment: 83.333333

    -- Thank you for using the Loan Calculator!

*/

struct Loan
{
    float loanAmount;
    float repaymentMonths;

    Loan()
    {
        this->loanAmount = Input::readPositiveFloatNumber("Enter the loan amount: ");
        this->repaymentMonths = Input::readPositiveFloatNumber("Enter the number of months to repay: ");
    }

    float calculateMonthlyPaymentAmount()
    {
        if (this->repaymentMonths == 0)
        {
            std::cout << "Number of months to repay cannot be zero.";
        }
        return this->loanAmount / this->repaymentMonths;
    }

    void display()
    {
        std::cout << "Loan Amount: " << this->loanAmount << std::endl;
        std::cout << "Months to Repay: " << this->repaymentMonths << std::endl;
        std::cout << "Monthly Payment: " << this->calculateMonthlyPaymentAmount() << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Loan Calculator");

    Loan loan;
    loan.display();

    Display::displayGoodbyeMessage("Thank you for using the Loan Calculator");

    return 0;
}
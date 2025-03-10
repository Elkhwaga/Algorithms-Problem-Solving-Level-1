#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the number of pennies, nickels, dimes, quarters, and dollars in a piggy bank and then prints the total amount of money in the piggy bank.
        -- The program should use a function to read the number of each type of coin and a function to calculate the total amount of money in the piggy bank.

    - #include "./lib/input.h" -> Input::readPositiveNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the number of penny: 1
        -- Enter the number of nickels: 1
        -- Enter the number of dimes: 1
        -- Enter the number of quarters: 1
        -- Enter the number of dollars: 1

    -----------------------------------------------------------------
    - Example Output:
        -- The total amount of money in the piggy bank is: $1.05

    -- Thank you for using the Piggy Bank Calculator!
*/

enum piggyBank
{
    PENNY = 1,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25,
    DOLLAR = 100
};

struct Money
{
    int penny;
    int nickels;
    int dimes;
    int quarters;
    int dollars;
    int totalPennies = 0;
    float totalDollars = 0;
};

Money GetMoney()
{
    Money money;
    money.penny = Input::readPositiveNumber("Enter the number of penny: ");
    money.nickels = Input::readPositiveNumber("Enter the number of nickels: ");
    money.dimes = Input::readPositiveNumber("Enter the number of dimes: ");
    money.quarters = Input::readPositiveNumber("Enter the number of quarters: ");
    money.dollars = Input::readPositiveNumber("Enter the number of dollars: ");

    money.totalPennies = (money.penny * PENNY) +
                         (money.nickels * NICKEL) +
                         (money.dimes * DIME) +
                         (money.quarters * QUARTER) +
                         (money.dollars * DOLLAR);
    money.totalDollars = (float)money.totalPennies / DOLLAR;
    return money;
}

void PrintResult(Money money)
{
    std::cout << "Total pennies: " << money.totalPennies << std::endl;
    std::cout << "Total dollars: " << money.totalDollars << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Piggy Bank Calculator!");

    Money money = GetMoney();
    PrintResult(money);

    Display::displayGoodbyeMessage("Thank you for using the Piggy Bank Calculator!");

    return 0;
}
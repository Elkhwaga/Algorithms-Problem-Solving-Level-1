#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that simulates an ATM machine.
        -- The program should prompt the user to enter a PIN.

    {
        - #include "input.h" -> Input::readPIN
        - #include "input.h" -> Input::readPositiveFloatNumber
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Please set your PIN first.
        -- Enter a 4-digit PIN: 1234
        -- Enter your balance: 1000
        -- Enter a 4-digit PIN: 1234

    -----------------------------------------------------------------
    - Example Output:
        -- PIN set successfully.
        -- Enter your 4-digit PIN (3 attempts left).
        -- PIN accepted. Access granted!
        -- Balance: $1000

    -- Goodbye!
*/

struct ATM
{
    int pin;
    double balance;
    int attemptsLeft;

    // Constructor to initialize the ATM with a default PIN and attempts left
    ATM() : pin(0), attemptsLeft(3), balance(0) {};

    // Function to set the PIN for the ATM
    void setPIN()
    {
        this->pin = Input::readPIN();
        std::cout << "PIN set successfully." << std::endl;
    }

    void setBalance()
    {
        this->balance = Input::readPositiveFloatNumber("Enter your balance: ");
    }

    // Function to validate the PIN entered by the user
    bool validatePIN(int enteredPIN)
    {
        return this->pin == enteredPIN;
    }

    // Function to simulate ATM access
    void accessATM()
    {
        if (pin == 0)
        {
            std::cout << "Please set your PIN first.\n";
            setPIN();
            setBalance();
        }

        while (attemptsLeft > 0)
        {
            std::cout << "Enter your 4-digit PIN (" << attemptsLeft << " attempts left).\n";
            int enteredPIN = Input::readPIN();

            if (validatePIN(enteredPIN))
            {
                std::cout << "PIN accepted. Access granted!\n";
                std::cout << "Balance: $" << balance << std::endl;
                system("color 2F");
                return;
            }
            else
            {
                attemptsLeft--;
                std::cout << "Incorrect PIN. ";
                if (attemptsLeft > 0)
                {
                    std::cout << "Try again.\n";
                    system("color 6F");
                }
                else
                {
                    std::cout << "No attempts left. Access denied.\n";
                    system("color 4F");
                }
            }
        }
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the ATM!");

    ATM atm;
    atm.accessATM();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
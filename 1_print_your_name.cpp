#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a function that prints your name
        -- The function should take the name as a parameter and print it

        {
            - #include "display.h" -> Display::displayWelcomeMessage
            - #include "display.h" -> Display::displayGoodbyeMessage
        }

    -----------------------------------------------------------------
    - Input:
        -- Mohamed Elkhwaga

    -----------------------------------------------------------------
    -Output:
        -- Your name is: Mohamed Elkhwaga

    -- Goodbye!
*/

void printName(std::string name)
{
    std::cout << "Your name is: " << name << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Your Name!");
    printName("Mohamed Elkhwaga");
    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
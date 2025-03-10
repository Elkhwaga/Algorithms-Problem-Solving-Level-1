#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter their name and then prints it out.
        -- The program should use a function to read the name and a function to print it out.

    - #include "input.h" -> Input::readString

    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter your name: Mohamed Elkhwaga

    -----------------------------------------------------------------
    - Example Output:
        -- Your name is: Mohamed Elkhwaga

    -- Goodbye!
*/

void PrintName(std::string name)
{
    std::cout << "Your name is: " << name << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Your Name!");
    PrintName(Input::readString("Enter your name: "));
    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
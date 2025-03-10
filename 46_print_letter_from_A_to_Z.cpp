#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prints the letters A to Z.
        -- The program should use a loop to print the letters one by one.

    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Output:
        -- A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

    -- Thank you for using the Program that Prints Letters A to Z!

*/

void printLettersAToZ()
{
    for (short i = 65; i <= 90; i++)
    {
        std::cout << char(i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Letters A to Z!");

    printLettersAToZ();

    Display::displayGoodbyeMessage("Thank you for using the Program that Prints Letters A to Z!");

    return 0;
}
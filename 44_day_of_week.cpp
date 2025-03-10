#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the day of the week (1-7).
        -- The program should use a switch statement to print the name of the day of the week.

    - #include "input.h" -> Input::readNumberAndValidate
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the day of the week (1-7): 3

    -----------------------------------------------------------------
    - Example Output:
        -- The day of the week is Tuesday

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the day of the week (1-7): 8

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a number between 1 and 7.

    -- Goodbye!

*/

struct DayHandler
{
    short day;

    DayHandler()
    {
        this->menu();
        this->day = Input::readNumberAndValidate("Enter the day of the week (1-7): ", 1, 7);
    }

    void menu()
    {
        std::cout << "1. Sunday" << std::endl;
        std::cout << "2. Monday" << std::endl;
        std::cout << "3. Tuesday" << std::endl;
        std::cout << "4. Wednesday" << std::endl;
        std::cout << "5. Thursday" << std::endl;
        std::cout << "6. Friday" << std::endl;
        std::cout << "7. Saturday" << std::endl;
    }

    std::string getDayName()
    {
        std::string dayName[7] = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"};

        return dayName[this->day - 1];
    }

    void printSelectedDay()
    {
        std::cout << "The day of the week is " << this->getDayName() << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Day of the Week Program!");

    DayHandler dayHandler;
    dayHandler.printSelectedDay();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
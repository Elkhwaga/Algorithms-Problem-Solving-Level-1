#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the number of hours and converts it into weeks and days.
        -- The program should use constants to represent the number of hours in a day and the number of days in a week.

    - #include "input.h" -> Input::readPositiveNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the number of hours: 168

    -----------------------------------------------------------------
    - Example Output:
        -- Hours: 168 hours
        -- Weeks: 4.00 week(s)
        -- Days: 21.00 day(s)

    -- Thank you for using the Hours to Weeks and Days Converter!
*/

struct TaskDuration
{
    const int DAY_OF_WEEK = 24;
    const int WEEK = 7;

    int hours;

    TaskDuration()
    {
        this->hours = Input::readPositiveNumber("Enter the number of hours: ");
    }

    float getDays()
    {
        return (float)hours / DAY_OF_WEEK;
    }

    float getWeek()
    {
        return (float)hours / (WEEK * DAY_OF_WEEK);
    }
    // Function to convert hours into weeks and days
    void printWeekAndDays()
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Hours: " << this->hours << " hours" << std::endl;
        std::cout << "Days: " << this->getDays() << " day(s)" << std::endl;
        std::cout << "Weeks: " << this->getWeek() << " week(s)" << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Hours to Weeks and Days Converter!");

    TaskDuration taskDuration;
    taskDuration.printWeekAndDays();

    Display::displayGoodbyeMessage("Thank you for using the Hours to Weeks and Days Converter!");

    return 0;
}
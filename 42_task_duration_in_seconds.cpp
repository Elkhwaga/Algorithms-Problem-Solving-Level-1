#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the number of days, hours, minutes, and seconds for a task.
        -- The program should calculate the total number of seconds for the task and display the result.

    {
        - #include "input.h" -> Input::readPositiveNumber
    }
    {
        - #include "display.h" -> Display::displayGoodbyeMessage
        - #include "display.h" -> Display::displayWelcomeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the number of days: 2
        -- Enter the number of hours: 3
        -- Enter the number of minutes: 4
        -- Enter the number of seconds: 5

    -----------------------------------------------------------------
    - Example Output:
        -- Total seconds: 9005

    -- Goodbye!
*/

struct TaskDuration
{
    const int SECONDS_PER_MINUTE = 60;
    const int SECONDS_PER_HOUR = 60 * SECONDS_PER_MINUTE;
    const int SECONDS_PER_DAY = 24 * SECONDS_PER_HOUR;

    int days;
    int hours;
    int minutes;
    int seconds;

    TaskDuration()
    {
        this->days = Input::readPositiveNumber("Enter the number of days: ");
        this->hours = Input::readPositiveNumber("Enter the number of hours: ");
        this->minutes = Input::readPositiveNumber("Enter the number of minutes: ");
        this->seconds = Input::readPositiveNumber("Enter the number of seconds: ");
    }

    int calculateTotalSeconds() const
    {
        return this->days * SECONDS_PER_DAY +
               this->hours * SECONDS_PER_HOUR +
               this->minutes * SECONDS_PER_MINUTE +
               this->seconds;
    }

    void printTaskDuration(const TaskDuration &duration)
    {

        std::cout << "Total seconds: " << this->calculateTotalSeconds() << std::endl;
    }
};

int main()
{
    Display::displayGoodbyeMessage("Welcome to the Task Duration Program!");

    TaskDuration duration;
    duration.printTaskDuration(duration);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
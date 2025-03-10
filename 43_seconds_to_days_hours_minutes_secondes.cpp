#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the duration of a task in seconds.
        -- The program should calculate and display the duration in days, hours, minutes, and seconds.

    - #include "input.h" -> Input::readPositiveNumber
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the number of seconds: 3600

    -----------------------------------------------------------------
    - Example Output:
        -- Formatted duration: 0 : 1 : 0 : 0

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the number of seconds: -3600

    -----------------------------------------------------------------
    - Example Output:
        -- Invalid input. Please enter a positive number.

    -- Thank you for using the Task Duration Calculator!
*/

struct TaskDuration
{
    const int SECONDS_PER_MINUTE = 60;
    const int SECONDS_PER_HOUR = 60 * SECONDS_PER_MINUTE;
    const int SECONDS_PER_DAY = 24 * SECONDS_PER_HOUR;

    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    int days = 0;

    // Constructor to initialize task duration
    TaskDuration()
    {
        this->seconds = Input::readPositiveNumber("Enter the number of seconds: ");
    }

    void calculateSecondsDuration()
    {
        this->days = seconds / SECONDS_PER_DAY;
        this->hours = (seconds % SECONDS_PER_DAY) / SECONDS_PER_HOUR;
        this->minutes = (seconds % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
        this->seconds = seconds % SECONDS_PER_MINUTE;
    }

    void printDuration()
    {
        this->calculateSecondsDuration();
        std::cout << "Formatted duration: "
                  << this->days << " : "
                  << this->hours << " : " << this->minutes << " : " << this->seconds << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Task Duration Calculator!");

    TaskDuration duration;
    duration.printDuration();

    Display::displayGoodbyeMessage("Thank you for using the Task Duration Calculator!");

    return 0;
}
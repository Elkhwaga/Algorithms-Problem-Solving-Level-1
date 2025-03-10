#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter their age and then checks if it is between 18 and 45.
        -- The program should keep prompting the user to enter a valid age until they provide one.

    - #include "./lib/input.h" -> Input::readNumberAndValidate
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter your age: 25

    -----------------------------------------------------------------
    - Example Output:
        -- The valid number is: 25

    -- Goodbye!
*/

const int MIN_AGE = 18;
const int MAX_AGE = 45;

int main()
{
    Display::displayWelcomeMessage("Welcome to the Age Validation Program!");

    int number = Input::readNumberAndValidate("Enter your age: ", MIN_AGE, MAX_AGE);

    if (number == -1)
    {
        std::cout << "Failed to get a valid age.\n";
        return -1;
    }

    std::cout << "The valid number is: " << number << std::endl;

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number between 1 and 50. The program should keep prompting the user to enter a valid number until they provide one.
        -- The program should use a function to read the number from the user and a function to check if the number is valid.

        - #include "./lib/input.h" -> Check::readNumberAndValidate
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 40

    -----------------------------------------------------------------
    - Example Output:
        -- The valid number is: 40

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 60

    -----------------------------------------------------------------
    - Example Output:
        -- Error: Invalid input please enter a valid integer between 1 AND 50 you have 2 attempts.
        -- Enter a number: 40
        -- The valid number is: 40

    -- Thank you for using the Number Validation Program!
*/

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 50;

int main()
{
    Display::displayWelcomeMessage("Welcome to the Number Validation Program!");

    int number = Input::readNumberAndValidate("Enter a number: ", MIN_NUMBER, MAX_NUMBER);

    if (number == -1)
    {
        std::cout << "Failed to get a valid number.\n";
        return -1;
    }

    std::cout << "The valid number is: " << number << std::endl;

    Display::displayGoodbyeMessage("Thank you for using the Number Validation Program!");

    return 0;
}
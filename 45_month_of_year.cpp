#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter a number between 1 and 12. The program should keep prompting the user to enter a valid number until they provide one.

    - #include "input.h" -> Input::readNumberAndValidate
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter a number: 5

    -----------------------------------------------------------------
    - Example Output:
        -- The valid number is: 5

    -- Thank you for using the Month of the Year Program!
*/

struct MonthHandler
{
    short month;

    MonthHandler()
    {
        this->month = Input::readNumberAndValidate("Enter the month of the year (1-12): ", 1, 12);
    }

    void menu()
    {
        std::cout << "1. January" << std::endl;
        std::cout << "2. February" << std::endl;
        std::cout << "3. March" << std::endl;
        std::cout << "4. April" << std::endl;
        std::cout << "5. May" << std::endl;
        std::cout << "6. June" << std::endl;
        std::cout << "7. July" << std::endl;
        std::cout << "8. August" << std::endl;
        std::cout << "9. September" << std::endl;
        std::cout << "10. October" << std::endl;
        std::cout << "11. November" << std::endl;
        std::cout << "12. December" << std::endl;
    }

    std::string getMonthName() const
    {
        std::string monthNames[12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August", "September",
            "October", "November", "December"};

        return monthNames[this->month - 1];
    }

    void printSelectedMonth()
    {
        std::cout << "You selected: " << this->getMonthName() << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Month of the Year Program!");

    MonthHandler handler;
    handler.printSelectedMonth();

    Display::displayGoodbyeMessage("Thank you for using the Month of the Year Program!");

    return 0;
}
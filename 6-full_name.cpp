#include "./lib/input.h"
#include "./lib/enums.h"
#include "./lib/utils.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter their first name and last name.
        -- The program should create an object of type stInfomation and store the first name and last name in the object.
        -- The program should then use the object to print out the full name in different formats.

    {
        - #include "input.h" -> Input::readName
        - #include "input.h" -> Input::readNumberInRange
    }
    - #include "enums.h" -> Enums::NameFormat
    - #include "utils.h" -> Utils::upperAllLetterOfEachWord
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter First Name: Mohamed
        -- Enter Last Name: Elkhwaga

    -----------------------------------------------------------------
    - Example Output:
        -- Choose Display Format:
        -- 1. Normal Format (First Last)
        -- 2. Formal Format (Last First)
        -- 3. Initials Format (F.L.)
        -- 4. Uppercase Format (FIRST LAST)
        -- 5. Lowercase Format (first last)
        -- Enter your choice (1-5): 1

        -- The full name is: Mohamed Elkhwaga

    -- Goodbye!
*/

struct stInfomation
{
    std::string firstName;
    std::string lastName;

    stInfomation()
    {

        this->firstName = Input::readName("Enter First Name: ");
        this->lastName = Input::readName("Enter Last Name: ");
    }

    stInfomation(std::string firstName, std::string lastName)
    {
        Display::displayWelcomeMessage("Welcome to the Program that Prints Your Name!");

        this->firstName = firstName;
        this->lastName = lastName;
    }

    void menu()
    {
        std::cout << "\nChoose Display Format:" << std::endl;
        std::cout << "1. Normal Format (First Last)" << std::endl;
        std::cout << "2. Formal Format (Last First)" << std::endl;
        std::cout << "3. Initials Format (F.L.)" << std::endl;
        std::cout << "4. Uppercase Format (FIRST LAST)" << std::endl;
        std::cout << "5. Lowercase Format (first last)" << std::endl;
    }

    std::string getFullName()
    {
        return this->firstName + " " + this->lastName;
    }

    std::string getName(Enums::NameFormat format = Enums::NameFormat::NORMAL_CASE)
    {
        std::string fullName = "";
        switch (format)
        {
        case Enums::NameFormat::NORMAL_CASE:
            fullName = this->getFullName();
            break;

        case Enums::NameFormat::FORMAL_CASE:
            fullName = this->lastName + " " + this->firstName;
            break;

        case Enums::NameFormat::INITIALS_CASE:
            fullName = std::string(1, this->firstName[0]) + "." + std::string(1, this->lastName[0]) + ".";
            break;

        case Enums::NameFormat::UPPERCASE_CASE:
            fullName = Utils::upperAllLetterOfEachWord(this->getFullName());
            break;

        case Enums::NameFormat::SMALL_CASE:
            fullName = Utils::lowerAllLetterOfEachWord(this->getFullName());
            break;
        }
        return fullName;
    }

    void printFullName()
    {
        this->menu();

        int choice = Input::readNumberInRange("Enter your choice (1-5): ", 1, 5);
        std::cout << "\nYour Full Name: " << this->getName(static_cast<Enums::NameFormat>(choice)) << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Your Name!");

    stInfomation info;
    info.printFullName();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}

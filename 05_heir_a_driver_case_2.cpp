#include "./lib/input.h"
#include "./lib/enums.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter their first name, middle name, last name, age, phone number, and whether they have a driver license and a recommendation.
        -- The program should create an object of type InformationDriver and store the information in the object.
        -- The program should then use the object to print out the information in different formats.

    {
        - #include "input.h" -> Input::readName
        - #include "input.h" -> Input::readPositiveNumber
        - #include "input.h" -> Input::readPhoneNumber
        - #include "input.h" -> Input::readChoice
    }
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    - #include "enums.h" -> Enums::ChoiceStatus

    -----------------------------------------------------------------
    - Example Input:
        -- Enter First Name: Mohamed
        -- Enter Middle Name: Mohamed
        -- Enter Last Name: Elkhwaga
        -- Enter Age: 25
        -- Enter Phone Number: 0123456789
        -- Do you have a driver license? (Y/N): Y
        -- Do you have a recommendation? (Y/N): Y

    -----------------------------------------------------------------
    - Example Output:
        -- The information is:
        -- First Name: Mohamed
        -- Middle Name: Mohamed
        -- Last Name: Elkhwaga
        -- Age: 25
        -- Phone Number: 0123456789
        -- Has Driver License: Yes
        -- Has Recommendation: Yes

        -- The information is:
        -- First Name: Mohamed
        -- Middle Name: Mohamed
        -- Last Name: Elkhwaga
        -- Age: 25
        -- Phone Number: 0123456789
        -- Has Driver License: Yes
        -- Has Recommendation: No

        -- Has Accepted: Yes

    -- Goodbye!
*/

struct InformationDriver
{
    std::string firstName;
    std::string middleName;
    std::string lastName;
    short age;
    std::string phoneNumber;
    bool hasDriverLicense = false;
    bool hasRecommendation = false;

    InformationDriver()
    {

        this->firstName = Input::readName("Enter First Name: ");
        this->middleName = Input::readName("Enter Middle Name: ");
        this->lastName = Input::readName("Enter Last Name: ");
        this->age = Input::readPositiveNumber("Enter Age: ");
        this->phoneNumber = Input::readPhoneNumber();
        this->hasDriverLicense = Input::readChoice("Do you have a driver license? (Y/N): ");
        this->hasRecommendation = Input::readChoice("Do you have a recommendation? (Y/N): ");
    }

    InformationDriver(
        std::string firstName,
        std::string middleName,
        std::string lastName,
        short age,
        std::string phoneNumber,
        bool hasDriverLicense,
        bool hasRecommendation)
    {
        Display::displayWelcomeMessage("Welcome to the Driver Information Program!");
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
        this->age = age;
        this->phoneNumber = phoneNumber;
        this->hasDriverLicense = hasDriverLicense;
        this->hasRecommendation = hasRecommendation;
    }

    bool hasAccepted()
    {
        return this->hasRecommendation == Enums::ChoiceStatus::YES ||
               ((this->age >= 21 && this->age <= 50) &&
                (this->hasDriverLicense == Enums::ChoiceStatus::YES));
    }

    void printInformationDriver()
    {
        std::cout << "\nYour Driver Information:\n";
        std::cout << "-------------------\n";
        std::cout << "First Name: " << this->firstName << std::endl;
        std::cout << "Middle Name: " << this->middleName << std::endl;
        std::cout << "Last Name: " << this->lastName << std::endl;
        std::cout << "Age: " << this->age << std::endl;
        std::cout << "Phone Number: " << this->phoneNumber << std::endl;

        (hasAccepted())
            ? std::cout << "Hire a driver" << std::endl
            : std::cout << "Reject a driver" << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Driver Information Program!");

    InformationDriver driver;
    driver.printInformationDriver();

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
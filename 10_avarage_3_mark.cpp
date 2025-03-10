#include "./lib/input.h"
#include "./lib/check.h"
#include "./lib/utils.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter the first name, last name, and marks for three subjects (Arabic, Math, and English).
        -- The program should create an object of type Student and store the entered information in the object.
        -- The program should then use the object to calculate the total score, average, and academic status.

    {
        - #include "input.h" -> Input::readFullName
        - #include "input.h" -> Input::readPositiveNumber
        - #include "input.h" -> Input::readNumberInRange
    }
    {
        - #include "check.h" -> Check::checkStatus
        - #include "check.h" -> Check::checkMark
    }
        - #include "utils.h" -> Utils::clearInputBuffer
    {
        - #include "display.h" -> Display::displayWelcomeMessage
        - #include "display.h" -> Display::displayGoodbyeMessage
    }

    ----------------------------------------------------------------------------
    - Example Input:
        -- Enter first name: Ahmed
        -- Enter last name: Ali
        -- Enter Arabic score: 50
        -- Enter Math score: 70
        -- Enter English score: 80

    - Example Output:
        -- Student Name: Ahmed Ali
        -- Total Score: 180
        -- Average: 60
        -- Academic Status: PASS

    -- Goodbye!

*/

struct Student
{
    struct SubjectMarks
    {
        float arabicScore;
        float mathScore;
        float englishScore;

        SubjectMarks() : arabicScore(0), mathScore(0), englishScore(0) {}

        float getTotalScore() const
        {
            return (this->arabicScore + this->mathScore + this->englishScore);
        }

        float getAverage() const
        {
            return this->getTotalScore() / 3;
        }

        Enums::Status checkAcademicStatus(float score)
        {
            return Check::checkStatus(score);
        }

        std::string getStatus() const
        {
            return (Check::checkMark(this->getAverage(), 150)) ? "PASS" : "FAIL";
        }
    };

    struct StudentInfo
    {
        std::string firstName;
        std::string lastName;
        std::string fullName;
        SubjectMarks marks;
        float average;
        float totalScore;
        Enums::Status status;

        StudentInfo() : firstName(""), lastName(""), fullName(""), marks(), average(0), totalScore(0), status(Enums::Status::FAIL) {}

        void menu()
        {
            std::cout << "\nChoose Display Format Full Name:" << std::endl;
            std::cout << "1. Normal Format (First Last)" << std::endl;
            std::cout << "2. Formal Format (Last First)" << std::endl;
            std::cout << "3. Initials Format (F.L.)" << std::endl;
            std::cout << "4. Uppercase Format (FIRST LAST)" << std::endl;
            std::cout << "5. Lowercase Format (first last)" << std::endl;
        }

        std::string getFullName()
        {
            return this->fullName = this->firstName + " " + this->lastName;
        }

        void getName(Enums::NameFormat format = Enums::NameFormat::NORMAL_CASE)
        {
            switch (format)
            {
            case Enums::NameFormat::NORMAL_CASE:
                this->fullName = this->getFullName();
                break;

            case Enums::NameFormat::FORMAL_CASE:
                this->fullName = this->lastName + " " + this->firstName;
                break;

            case Enums::NameFormat::INITIALS_CASE:
                this->fullName = std::string(1, this->firstName[0]) + "." + std::string(1, this->lastName[0]) + ".";
                break;

            case Enums::NameFormat::UPPERCASE_CASE:
                this->fullName = Utils::upperAllLetterOfEachWord(this->getFullName());
                break;

            case Enums::NameFormat::SMALL_CASE:
                this->fullName = Utils::lowerAllLetterOfEachWord(this->getFullName());
                break;
            }
        }
    };

    StudentInfo info;

    Student()
    {

        this->info.firstName = Input::readName("Enter First Name: ");
        this->info.lastName = Input::readName("Enter Last Name: ");
        this->info.marks.arabicScore = Input::readNumberInRange("Enter Arabic Score: ", 0, 100);
        this->info.marks.mathScore = Input::readNumberInRange("Enter Math Score: ", 0, 100);
        this->info.marks.englishScore = Input::readNumberInRange("Enter English Score: ", 0, 100);
        this->info.average = this->info.marks.getAverage();
        this->info.totalScore = this->info.marks.getTotalScore();
        this->info.status = this->info.marks.checkAcademicStatus(this->info.totalScore);
    }

    Student(std::string firstName, std::string lastName, float arabicScore, float mathScore, float englishScore)
    {
        this->info.firstName = firstName;
        this->info.lastName = lastName;
        this->info.marks.arabicScore = arabicScore;
        this->info.marks.mathScore = mathScore;
        this->info.marks.englishScore = englishScore;
        this->info.average = this->info.marks.getAverage();
        this->info.totalScore = this->info.marks.getTotalScore();
        this->info.status = this->info.marks.checkAcademicStatus(this->info.totalScore);
    }

    void setName()
    {
        this->info.menu();
        char choice = Input::readNumberInRange("Enter your choice: ", 1, 5);
        this->info.getName(static_cast<Enums::NameFormat>(choice));
    }

    void display()
    {
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "First Name    : " << info.firstName << std::endl;
        std::cout << "Last Name     : " << info.lastName << std::endl;
        std::cout << "Full Name     : " << info.fullName << std::endl;
        std::cout << "Arabic Score  : " << info.marks.arabicScore << std::endl;
        std::cout << "Math Score    : " << info.marks.mathScore << std::endl;
        std::cout << "English Score : " << info.marks.englishScore << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Total     : " << info.totalScore << std::endl;
        std::cout << "Average   : " << info.average << "%" << std::endl;
        std::cout << "Status    : " << info.marks.getStatus() << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Program that Prints Your Informatio Student!");

    Student student;
    char choice;

    do
    {
        student.setName();
        student.display();
        choice = Input::readChoice("Do you want to continue? (Y/N): ");
        Utils::clearScreen();

    } while (Check::isContinue(choice) == Enums::ChoiceStatus::YES);

    Display::displayGoodbyeMessage("Goodbye!");

    return 0;
}
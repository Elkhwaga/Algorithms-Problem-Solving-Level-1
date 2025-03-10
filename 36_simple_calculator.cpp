#include "./lib/input.h"
#include "./lib/display.h"

/*
    @Author: Mohamed Elkhwaga
    @version 1.0


    - Write a program that prompts the user to enter two numbers and then performs an operation on them.
        -- The program should use a function to read the numbers and a function to calculate the result.

    - #include "./lib/input.h" -> Input::readPositiveFloatNumber
    {
        - #include "./lib/display.h" -> Display::displayWelcomeMessage
        - #include "./lib/display.h" -> Display::displayGoodbyeMessage
    }

    -----------------------------------------------------------------
    - Example Input:
        -- Enter the first number: 10
        -- Enter the second number: 5
        -- 1. Add
        -- 2. Subtract
        -- 3. Multiply
        -- 4. Divide
        -- Enter your choice: 1

    -----------------------------------------------------------------
    - Example Output:
        -- The result is: 15

    -- Thank you for using the Simple Calculator!
*/

struct Calculator
{
    enum Operation
    {
        ADD = 1,
        SUBTRACT = 2,
        MULTIPLY = 3,
        DIVIDE = 4
    };

    float num1;
    float num2;
    float result;
    Operation operation;

    Calculator()
    {
        this->num1 = Input::readPositiveFloatNumber("Enter the first number: ");
        this->num2 = Input::readPositiveFloatNumber("Enter the second number: ");
        this->operation = this->setOperation();
        this->result = this->calculate();
    }

    void menu()
    {
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Subtract" << std::endl;
        std::cout << "3. Multiply" << std::endl;
        std::cout << "4. Divide" << std::endl;
    }

    Operation setOperation()
    {
        this->menu();
        int choice = Input::readNumberAndValidate("Enter your choice: ", 1, 4);
        return static_cast<Operation>(choice);
    }

    float add(float num1, float num2)
    {
        return num1 + num2;
    }

    float subtract(float num1, float num2)
    {
        return num1 - num2;
    }

    float multiply(float num1, float num2)
    {
        return num1 * num2;
    }

    float divide(float num1, float num2)
    {
        if (num2 == 0)
        {
            return -1;
        }

        return num1 / num2;
    }
    float calculate()
    {
        float temp;
        switch (this->operation)
        {
        case ADD:
            temp = add(this->num1, this->num2);
            break;
        case SUBTRACT:
            temp = subtract(this->num1, this->num2);
            break;
        case MULTIPLY:
            temp = multiply(this->num1, this->num2);
            break;
        case DIVIDE:
            temp = divide(this->num1, this->num2);
            break;
        }

        return temp;
    }

    void printResult()
    {
        if (this->result == -1)
        {
            std::cout << "Error: Division by zero" << std::endl;
            return;
        }
        std::cout << "Result: " << this->result << std::endl;
    }
};

int main()
{
    Display::displayWelcomeMessage("Welcome to the Calculator!");

    Calculator calculator;
    calculator.printResult();

    Display::displayGoodbyeMessage("Thank you for using the Calculator!");
    return 0;
}
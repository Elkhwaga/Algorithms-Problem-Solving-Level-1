#include <iostream>
#include <sstream>

namespace Error
{
    /**
     * @brief Generates a detailed error message with remaining attempts
     * @param baseMessage The primary error message
     * @param remainingAttempts Number of attempts left
     * @return Formatted error message string
     */
    std::string formatErrorMessage(const std::string &baseMessage, int remainingAttempts)
    {
        std::stringstream ss;
        ss << baseMessage << "\n"
           << "Remaining attempts: " << remainingAttempts << "\n"
           << "Please try again...";
        return ss.str();
    }
}
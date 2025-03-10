#pragma once
#include "enums.h"
#include "constant.h"
#include <cmath>

struct Check
{
	static bool checkPrime(int number)
	{
		if (number == 1)
			return false;
		if (number == 2)
			return true;
		if (number % 2 == 0)
			return false;

		int M = sqrt(number);
		for (int i = 3; i <= M; i += 2)
		{
			if (number % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	static Enums::PrimeOrNot isPrimeOrNot(int number)
	{
		return (checkPrime(number)) ? Enums::PrimeOrNot::PRIME : Enums::PrimeOrNot::NOT_PRIME;
	}

	static bool isEven(int n)
	{
		return n % 2 == 0;
	}

	static bool isOdd(int n)
	{
		return n % 2 == 1;
	}

	static Enums::OddOrEven GetNumberType(int number)
	{
		return (number % 2 == 0) ? Enums::OddOrEven::EVEN : Enums::OddOrEven::ODD;
	}

	static bool isZero(int number)
	{
		return number == 0;
	}

	static Enums::ChoiceStatus isContinue(char choice)
	{
		return (choice == 'Y' || choice == 'y') ? Enums::ChoiceStatus::YES : Enums::ChoiceStatus::NO;
	}

	static bool checkMark(float mark, float passMark = 50.0)
	{
		return mark >= passMark;
	}

	static Enums::Status checkStatus(int mark)
	{
		return (checkMark(mark)) ? Enums::Status::PASS : Enums::Status::FAIL;
	}

	/**
	 * @brief Validates if a dimension is within acceptable range
	 * @param dimension The dimension to validate
	 * @return bool True if dimension is valid
	 */
	static bool isValidDimension(double dimension)
	{
		return dimension > Constant::MIN_LENGTH && dimension <= Constant::MAX_LENGTH;
	}

	static bool isValidateNumberInRange(int number, int MIN_NUMBER, int MAX_NUMBER)
	{
		if (number != static_cast<int>(number))
			return false;

		return number >= MIN_NUMBER && number <= MAX_NUMBER;
	}
};

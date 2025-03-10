#pragma once
#include <iostream>
#include <limits>

struct Utils
{
	static void clearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	static void clearScreen()
	{
		system("cls");
	}

	static void pause()
	{
		std::cout << "Press Enter to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	static void clearScreenAndPause()
	{
		clearScreen();
		pause();
	}

	static std::string lowerAllLetterOfEachWord(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}

	static std::string upperAllLetterOfEachWord(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
};

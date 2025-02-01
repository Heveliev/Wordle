// suggest_choosing_mode.cpp -- output of the offer to select a mode or exit

#include <iostream>

#include "../../Config.h"

void suggest_choosing_mode()
{
	std::cout << "Select a mode to start the game:" << std::endl;

	std::cout << Config::EXIT << ' ' << '-' << ' ';
	std::cout << "Exit" << '.' << std::endl;

	std::cout << Config::MODE_DAILY << ' ' << '-' << ' ';
	std::cout << "Wordle of the day" << '.' << std::endl;

	std::cout << Config::MODE_RANDOM << ' ' << '-' << ' ';
	std::cout << "Random Wordle" << '.' << std::endl;
}
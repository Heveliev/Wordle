// Wordle.cpp -- word guessing game

#include <iostream>

#include "Config.h"

int main()
{
	GameState game = GameState::NotStarted;


	std::cout << "Welcome to the Wordle game!" << std::endl << std::endl;

	while (game != GameState::End)
	{


		std::cout << "Select a mode to start the game:" << std::endl;

		std::cout << Config::EXIT << ' ' << '-' << ' ';
		std::cout << "Exit" << '.' << std::endl;

		std::cout << Config::MODE_DAILY << ' ' << '-' << ' ';
		std::cout << "Wordle of the day" << '.' << std::endl;

		std::cout << Config::MODE_RANDOM << ' ' << '-' << ' ';
		std::cout << "Random Wordle" << '.' << std::endl;

		game = GameState::End;
	}
}	
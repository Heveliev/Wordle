// print_info.cpp -- functions for working with information output

#include <iostream>

#include "../../Config.h"

// greetings -- output greeting to user
void greetings()
{
	std::cout << "Welcome to the Wordle game!" << std::endl << std::endl;
}


// parting -- output farewell to the user
void parting()
{
	std::cout << "Thanks for playing, we'll be waiting for you again!" << std::endl << std::endl;
}


// suggest_choosing_mode -- output of the offer to select a mode or exit
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


// notify_invalid_input -- output validation error
void notify_invalid_input(Validation validated)
{
    switch (validated)
    {
    case Validation::Empty:
        std::cout << "Contents cannot be empty." << std::endl;
        break;
    case Validation::Less:
        std::cout << "Shorter than necessary." << std::endl;
        break;
    case Validation::Digit:
        std::cout << "Cannot be a number." << std::endl;
        break;
    case Validation::SpecialSymbol:
        std::cout << "Cannot be a special character or the character you entered." << std::endl;
        break;
    case Validation::Larger:
    case Validation::ExitSymbol:
    case Validation::Validated:
        break;
    default:
        std::cout << "Unexpected result, contact the developer." << std::endl;
        break;
    }
}


// conclusion -- output of successful outcome and number of attempts
void conclusion(const int& quantity_attempts)
{
    std::cout << "Congratulations you guessed the word!" << std::endl;
    std::cout << "You made" << ' ' << quantity_attempts << ' ' << "tries!" << std::endl;
}
// validation.cpp -- validation functions

#include <string>
#include <algorithm>

#include "../Config.h"


// input_validation -- input word validation
Validation input_validation(std::string& input, const int& word_length)
{
	if (input.empty())
		return Validation::Empty;

	if (input.length() == 1 && input == std::to_string(Config::EXIT))
		return Validation::ExitSymbol;

	if (input.length() < word_length)
		return Validation::Less;

	if (input.length() > word_length)
	{

		input.substr(0, word_length);
		//return Validation::Larger;
	}


	for (int i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]))
			return Validation::Digit;
		if (!std::isalnum(input[i]))
			return Validation::SpecialSymbol;
	}

	std::transform(input.begin(), input.end(), input.begin(), std::toupper);
	return Validation::Validated;
}


// pick_mode -- select game mode
GameMode pick_mode(const int& input)
{
	switch (input)
	{
	case Config::MODE_DAILY:
		return GameMode::Daily;
	case Config::MODE_RANDOM:
		return GameMode::Random;
	default:
		return GameMode::Unknown;
	}
}


// process_tracking -- game state tracking function
GameState process_tracking(const int& input)
{
	switch (input)
	{
	case Config::EXIT:
		return GameState::End;
	case Config::MODE_DAILY:
	case Config::MODE_RANDOM:
		return GameState::InProgress;
	default:
		return GameState::NotStarted;
	}
}
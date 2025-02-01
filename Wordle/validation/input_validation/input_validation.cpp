// input_validation.cpp -- input word validation

#include <string>
#include <algorithm>

#include "../../Config.h"



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
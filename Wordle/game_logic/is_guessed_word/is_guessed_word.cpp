// is_guessed_word.cpp -- check if the word is guessed

#include <string>
#include <vector>

#include "../../Config.h"

bool is_guessed_word(const int& word_length, std::vector<S_LetterInfo>& word_letters)
{
	int quantity_guessed = 0;

	for (int i = 0; i < word_length; i++)
	{
		if (word_letters[i].is_guessed && word_letters[i].is_in_place)
		{
			quantity_guessed++;
		}

		if (quantity_guessed == word_length) return true;
	}
	return false;
}


// word_operations.cpp -- word operations

#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_map>

#include "../../Config.h"


// masked_word -- convert word to hidden characters
std::string masked_word(std::vector<S_LetterInfo>& LettersData, const int& word_length)
{
	std::string mask(word_length, Config::MASK_SYMBOL);

	if (word_length == 0 || LettersData.empty() || LettersData.size() != word_length) return mask;

	std::vector<int> available_indexes;

	for (int i = 0; i < word_length; i++)
	{
		if (LettersData[i].is_guessed && LettersData[i].is_in_place)
			mask[i] = LettersData[i].letter;
		else
			available_indexes.push_back(i);
	}

	if (!available_indexes.empty())
	{
		for (int i = 0; i < word_length; i++)
		{
			if (LettersData[i].is_guessed && !LettersData[i].is_in_place && !available_indexes.empty())
			{
				int random_index = rand() % available_indexes.size();
				int position = available_indexes[random_index];
				mask[position] = std::tolower(LettersData[i].letter);
				available_indexes.erase(available_indexes.begin() + random_index);
			}
		}
	}
	return mask;
}


// add_letters -- converting a word into an array of structures describing each letter
std::vector<S_LetterInfo> add_letters(const std::string& word, const int& word_length)
{
	std::vector<S_LetterInfo> LettersData;
	if (word_length == 0 || word.empty()) return LettersData;

	LettersData.resize(word_length);


	for (short i = 0; i < word_length; i++)
	{
		LettersData[i].letter = word[i];
		LettersData[i].index = i;
	}

	return LettersData;
}


// check_matches -- checking for matches between the input and the word to be guessed
void check_matches(const std::string& input, const int& word_length, std::vector<S_LetterInfo>& word_letters)
{
	if (input.empty() || word_length <= 0 || word_letters.empty()) return;

	std::unordered_map<char, int> letter_count;

	for (short i = 0; i < word_length; i++)
	{
		letter_count[word_letters[i].letter]++;
	}

	for (short i = 0; i < word_length; i++)
	{
		char user_letter = input[i];

		for (short j = 0; j < word_length; j++)
		{
			char target_letter = word_letters[j].letter;
			short target_index = word_letters[j].index;
			bool target_is_guessed = word_letters[j].is_guessed;

			if (user_letter == target_letter)
			{
				if (i == target_index)
				{
					word_letters[j].is_guessed = true;
					word_letters[j].is_in_place = true;
					letter_count[target_letter]--;
				}
				else
				{
					word_letters[j].is_guessed = true;
					letter_count[target_letter]--;
				}
			}
		}

	}
}


// is_guessed_word -- check if the word is guessed
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
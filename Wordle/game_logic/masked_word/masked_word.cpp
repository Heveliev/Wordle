// masked_word.cpp -- convert word to hidden characters

#include <string>
#include <vector>

#include "../../Config.h"

#include "../get_random_index/get_random_index.h"

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
				int random_index = get_random_index(available_indexes.size());
				int position = available_indexes[random_index];
				mask[position] = std::tolower(LettersData[i].letter);
				available_indexes.erase(available_indexes.begin() + random_index);
			}
		}
	}
	return mask;
}
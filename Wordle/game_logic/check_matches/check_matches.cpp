// check_matches.cpp -- checking for matches between the input and the word to be guessed

#include <string>
#include <vector>
#include <unordered_map>

#include "../../Config.h"

void check_matches(const std::string& input,const int& word_length, std::vector<S_LetterInfo>& word_letters)
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
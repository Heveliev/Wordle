//append_word.cpp -- filling an array with words from a file

#include <vector>
#include <string>

#include "../get_random_word/get_random_word.h"

void append_word(std::vector<std::string>& destination, std::vector<std::string>& source_words, const int& words_quantity)
{
	if (source_words.empty() || words_quantity <= 0) return;

	for (int i = 0; i < words_quantity; i++)
	{
		if (source_words.empty()) break;

		std::string word = get_random_word(source_words);

		destination.push_back(word);
	}
}
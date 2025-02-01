// get_random_word.cpp -- select random word from array

#include <vector>
#include <string>

#include "../get_random_index/get_random_index.h"

std::string get_random_word(std::vector<std::string>& words)
{
	if (words.empty()) return "";

	int index = get_random_index(words.size());
	std::string word = words[index];

	words.erase(words.begin() + index);
	return word;
}
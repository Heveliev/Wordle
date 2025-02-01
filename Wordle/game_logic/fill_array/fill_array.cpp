// fill_array .cpp -- filling an array with words from a common list of words

#include <vector>
#include <string>

#include "../../Config.h"

#include "../../file_operations/IO_words/IO_words.h"

#include "../append_word/append_word.h"

void fill_array(std::vector<std::string>& destination, 
	std::vector<std::string>& source_words,
	const std::string& path, const int& words_quantity)
{
	if (!source_words.empty() || path.empty() || words_quantity == 0) return;

	IO_words(path, source_words, FileOperation::Input, Config::MIN_QUANTITY_WORDS);
	destination.reserve(words_quantity);
	append_word(destination, source_words, words_quantity);
}
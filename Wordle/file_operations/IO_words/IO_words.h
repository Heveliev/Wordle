#pragma once

#include <vector>
#include <string>

#include "../../Config.h"

void IO_words(const std::string& file_name, std::vector<std::string>& words,
	FileOperation operation = FileOperation::Input, int words_countity = Config::MIN_QUANTITY_WORDS);
#pragma once

#include <string>
#include <vector>

#include "../Config.h"

void IO_DailyWord(const std::string& file_name, S_DailyWord& DailyWord, 
	FileOperation operation = FileOperation::Input);

std::string IO_string(const std::string& file_name, std::string content = "0",
	FileOperation operation = FileOperation::Input);

void IO_Stat(const std::string& file_name, S_Stat& statistic, bool is_first_launch = true,
	FileOperation operation = FileOperation::Input);

void IO_words(const std::string& file_name, std::vector<std::string>& words,
	FileOperation operation = FileOperation::Input, int words_countity = Config::MIN_QUANTITY_WORDS);
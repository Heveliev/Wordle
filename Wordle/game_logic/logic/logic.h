#pragma once

#include <string>
#include <vector>

#include "../../Config.h"

S_GameVariable init_GameVariable(const std::string& path);

std::string get_random_word(std::vector<std::string>& words);

void append_word(std::vector<std::string>& destination, std::vector<std::string>& source_words, 
	const int& words_quantity);

void fill_array(std::vector<std::string>& destination, std::vector<std::string>& source_words,
	const std::string& path, const int& words_quantity);

void first_launch(S_GameVariable& GameVariable, const std::string& path);

void init_words_array(std::string& path, S_GameVariable& GameVariable);

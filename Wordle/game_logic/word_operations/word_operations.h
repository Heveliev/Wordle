#pragma once

#include <string>
#include <vector>

#include "../../Config.h"

std::string masked_word(std::vector<S_LetterInfo>& LettersData, const int& word_length);

std::vector<S_LetterInfo> add_letters(const std::string& word, const int& word_length);

void check_matches(const std::string& input, const int& word_length, std::vector<S_LetterInfo>& word_letters);

bool is_guessed_word(const int& word_length, std::vector<S_LetterInfo>& word_letters);
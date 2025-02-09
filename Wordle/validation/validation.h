#pragma once 

#include <string>

#include "../Config.h"

Validation input_validation(std::string& input, const int& word_length);

GameMode pick_mode(const int& input);

GameState process_tracking(const int& input);
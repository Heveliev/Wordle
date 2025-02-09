// Wordle.cpp -- word guessing game

#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "Config.h"

//# "time"

//# "file"
#include "./fileoperations/fileoperations.h"

//# "validation"
#include "./validation/validation.h"

//# "logic"
#include "./game_logic/logic/logic.h"
#include "./game_logic/print_info/print_info.h"
#include "./game_logic/word_operations/word_operations.h"


int main()
{
	srand(std::time(nullptr));
	std::string path = std::filesystem::current_path().string() + Config::DATA_FOLDER;
	
	S_GameVariable GameVariable = init_GameVariable(path);


	if (GameVariable.is_first_launch || GameVariable.DailyWord.daily_word.empty())
	{
		first_launch(GameVariable, path);
	}


	greetings();


	while (GameVariable.game != GameState::End)
	{
		if (GameVariable.words.empty())
		{
			init_words_array(path, GameVariable);
		}




		if (GameVariable.game != GameState::InProgress)
		{
			suggest_choosing_mode();

			int* input = new int(0);

			std::cout << "Enter:" << ' ';
			std::cin >> *input;

			GameVariable.game = process_tracking(*input);
			GameVariable.mode = pick_mode(*input);

			delete input;
		}
		
		if (GameVariable.mode == GameMode::Daily)
		{
			std::string* word = new std::string{ GameVariable.DailyWord.daily_word};
			int word_length = word->length();
			
			std::vector<S_LetterInfo> LettersData = add_letters(*word, word_length);
			delete word;


			std::string* input = new std::string(std::to_string(0));

			int* quantity_attempts = new int(0);

			while (GameVariable.game != GameState::End)
			{
				if (GameVariable.DailyWord.is_word_guessed)
				{
					std::cout << "The word has already been guessed, try tomorrow" << std::endl;
					GameVariable.game = GameState::NotStarted;
					break;
				}

				std::string currentMask = masked_word(LettersData, word_length);

				std::cout << "Result:" << ' ' << currentMask << std::endl;

				std::cout << "Enter:" << ' ';
				std::cin >> *input;

				Validation validated = input_validation(*input, word_length);
				if (validated == Validation::ExitSymbol)
				{
					GameVariable.game = GameState::End;
					break;
				}

				if (validated != Validation::Validated)
				{
					notify_invalid_input(validated);
					continue;
				}

				check_matches(*input, word_length, LettersData);


				bool result = is_guessed_word(word_length, LettersData);

				(*quantity_attempts)++;

				if (result)
				{
					GameVariable.DailyWord.is_word_guessed = true;
					IO_DailyWord((path + Config::DAILY_WORD_FILE), GameVariable.DailyWord, FileOperation::Output);

					conclusion(*quantity_attempts);

					GameVariable.game = GameState::NotStarted;
					break;
				}

			}
			delete input;
			delete quantity_attempts;

		}
		else if (GameVariable.mode == GameMode::Random)
		{
			std::string* word = new std::string{get_random_word(GameVariable.words)};
			int word_length = word->length();
			
			std::vector<S_LetterInfo> LettersData = add_letters(*word, word_length);
			delete word;


			std::string* input = new std::string(std::to_string(0));

			int* quantity_attempts = new int(0);

			while(GameVariable.game != GameState::End)
			{
				std::string currentMask = masked_word(LettersData, word_length);

				std::cout << "Result:" << ' ' << currentMask << std::endl;

				std::cout << "Enter:" << ' ';
				std::cin >> *input;

				Validation validated = input_validation(*input, word_length);

				if (validated == Validation::ExitSymbol)
				{
					GameVariable.game = GameState::End;
					break;
				}

				if (validated != Validation::Validated)
				{
					notify_invalid_input(validated);
					continue;
				}

				check_matches(*input, word_length, LettersData);

				
				bool result = is_guessed_word(word_length, LettersData);
				(*quantity_attempts)++;

				if (result)
				{
					conclusion(*quantity_attempts);

					GameVariable.game = GameState::NotStarted;
					break;
				}

			}
			delete input;
			delete quantity_attempts;
		}




		IO_words((path + Config::RANDOM_WORDS_LIST_FILE), GameVariable.words, FileOperation::Output);
	}

	parting();

	return 0;
}	
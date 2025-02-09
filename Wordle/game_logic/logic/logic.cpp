// logic.cpp -- main logic of the application

#include <string>
#include <vector>
#include <cstdlib>

#include "../../Config.h"

#include "../../time/time.h"

#include "../../fileoperations/fileoperations.h"


// init_GameVariable -- initialization of game variables
S_GameVariable init_GameVariable(const std::string& path)
{
	S_GameVariable GameVariable;
	GameVariable.is_first_launch = is_same_day((path + Config::TIME_FILE));

	IO_Stat((path + Config::STAT_FILE), GameVariable.Statistic);

	GameVariable.words_quantity = Config::INIT_MIN_QUANTITY_WORDS * GameVariable.Statistic.average_multiplier;
	IO_words((path + Config::RANDOM_WORDS_LIST_FILE), GameVariable.words, FileOperation::Input, GameVariable.words_quantity);

	IO_DailyWord((path + Config::DAILY_WORD_FILE), GameVariable.DailyWord);

	return GameVariable;
}

// get_random_word -- select random word from array
std::string get_random_word(std::vector<std::string>& words)
{
	if (words.empty()) return "";

	int index = rand() % words.size();
	std::string word = words[index];

	words.erase(words.begin() + index);
	return word;
}


//append_word -- filling an array with words from a file
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


// fill_array -- filling an array with words from a common list of words
void fill_array(std::vector<std::string>& destination,
	std::vector<std::string>& source_words,
	const std::string& path, const int& words_quantity)
{
	if (!source_words.empty() || path.empty() || words_quantity == 0) return;

	IO_words(path, source_words, FileOperation::Input, Config::MIN_QUANTITY_WORDS);
	destination.reserve(words_quantity);
	append_word(destination, source_words, words_quantity);
}


// first_launch -- manipulations when first starting the game
void first_launch(S_GameVariable& GameVariable, const std::string& path)
{
	std::vector<std::string>* source_words = new std::vector<std::string>;

	fill_array(GameVariable.words, *source_words, (path + Config::WORDS_LIST_FILE), GameVariable.words_quantity);
	GameVariable.Statistic.yesterday_multiplier = GameVariable.Statistic.today_multiplier;
	GameVariable.Statistic.today_multiplier = Config::MULTIPLIER;
	IO_Stat((path + Config::STAT_FILE), GameVariable.Statistic, GameVariable.is_first_launch, FileOperation::Output);


	GameVariable.DailyWord.daily_word = get_random_word(*source_words);
	GameVariable.DailyWord.is_word_guessed = false;
	IO_DailyWord((path + Config::DAILY_WORD_FILE), GameVariable.DailyWord, FileOperation::Output);

	delete source_words;
}

//init_words_array -- filling the array that the user uses and updating the call statistics
void init_words_array(std::string& path, S_GameVariable& GameVariable)
{
	std::vector<std::string>* source_words = new std::vector<std::string>;

	fill_array(GameVariable.words, *source_words, (path + Config::WORDS_LIST_FILE), GameVariable.words_quantity);

	if (GameVariable.Statistic.today_multiplier < Config::MIN_QUANTITY_WORDS / Config::INIT_MIN_QUANTITY_WORDS)
		GameVariable.Statistic.today_multiplier++;

	IO_Stat((path + Config::STAT_FILE), GameVariable.Statistic, GameVariable.is_first_launch, FileOperation::Output);

	delete source_words;
}
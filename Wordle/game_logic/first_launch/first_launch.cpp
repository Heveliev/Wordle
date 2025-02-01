// first_launch.cpp -- manipulations when first starting the game


#include <vector>
#include <string>

#include "../../Config.h"

#include "../../file_operations/IO_Stat/IO_Stat.h"
#include "../../file_operations/IO_DailyWord/IO_DailyWord.h"


#include "../fill_array/fill_array.h"
#include "../get_random_word/get_random_word.h"


void first_launch(S_GameVariable& GameVariable, const std::string& path)
{
	std::vector<std::string>* source_words = new std::vector<std::string>;

	fill_array(GameVariable.words, *source_words, (path + Config::WORDS_LIST_FILE), GameVariable.words_quantity);
	GameVariable.Statistic.yesterday_multiplier = GameVariable.Statistic.today_multiplier;
	GameVariable.Statistic.today_multiplier = Config::MULTIPLIER;
	IO_Stat((path + Config::STAT_FILE), GameVariable.Statistic, GameVariable.is_first_launch, FileOperation::Output);


	GameVariable.DailyWord.daily_word = get_random_word(*source_words);
	GameVariable.DailyWord.is_word_guessed = false;
	IO_DailyWord((path + Config::DAILY_WORD_FILE), GameVariable.DailyWord,FileOperation::Output);

	delete source_words;
}
// init_GameVariable.cpp -- initialization of game variables

#include <string>

#include "../../Config.h"

#include "../../time/is_same_day/is_same_day.h"

#include "../../file_operations/IO_Stat/IO_Stat.h"
#include "../../file_operations/IO_words/IO_words.h"
#include "../../file_operations/IO_DailyWord/IO_DailyWord.h"

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
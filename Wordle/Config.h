#pragma once

#include <string>
#include <vector>

class Config
{
public:
		static constexpr int EXIT = 0;

		static constexpr int MODE_DAILY = 1;
		static constexpr int MODE_RANDOM = 2;


		static constexpr int MIN_QUANTITY_WORDS = 100;
		static constexpr int INIT_MIN_QUANTITY_WORDS = 10;
		static constexpr int MULTIPLIER = 1;

		static constexpr int TIME_COEFFICIENT = 24 * 60 * 60;

		static constexpr const char MASK_SYMBOL = '*';

		static constexpr const char* DATA_FOLDER = "/data/";
		static constexpr const char* TIME_FILE = "time.txt";
		static constexpr const char* RANDOM_WORDS_LIST_FILE = "random_words.txt";
		static constexpr const char* WORDS_LIST_FILE = "words.txt";
		static constexpr const char* STAT_FILE = "stat.txt";
		static constexpr const char* DAILY_WORD_FILE = "daily_word.txt";

};

enum class FileOperation
{
	Input,
	Output
};

enum class GameState
{
	NotStarted,
	InProgress,
	End,
	Bug
};

enum class GameMode
{
	Unknown,
	Daily,
	Random,
};

struct S_DailyWord
{
	bool is_word_guessed = false;
	std::string daily_word = "";
};

struct S_Stat
{
	int today_multiplier = Config::MULTIPLIER;
	int yesterday_multiplier = Config::MULTIPLIER;
	int average_multiplier = Config::MULTIPLIER;
};

struct S_GameVariable
{
	GameState game = GameState::NotStarted;
	GameMode mode = GameMode::Unknown;
	bool is_first_launch = true;
	S_Stat Statistic;
	int words_quantity = Config::INIT_MIN_QUANTITY_WORDS * Config::MULTIPLIER;
	std::vector<std::string> words;
	S_DailyWord DailyWord;
};

struct S_LetterInfo 
{
	char letter = '\0';
	int index = -1;
	bool is_guessed = false;
	bool is_in_place = false;
};

enum class Validation
{
	Empty,
	ExitSymbol,
	Less,
	Larger,
	Digit,
	SpecialSymbol,
	Validated,
};


enum class Complexity
{
	Low,
	Medium,
	High,
	VeryHigh
};
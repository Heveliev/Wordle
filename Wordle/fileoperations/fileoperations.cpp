// fileoperations.cpp -- functions for working with files

#include <string>
#include <fstream>
#include <sstream>
#include <vector>


#include "../Config.h"

#include "../game_logic/utility/utility.h"

// IO_DailyWord -- reading and writing daily word data to file
void IO_DailyWord(const std::string& file_name, S_DailyWord& DailyWord, FileOperation operation)
{
	std::fstream file;

	if (operation == FileOperation::Input)
	{
		file.open(file_name, std::ios::in);

		if (!file) return;

		file >> DailyWord.is_word_guessed;
		file >> DailyWord.daily_word;
	}
	else
	{
		file.open(file_name, std::ios::out);

		if (!file) return;

		file << DailyWord.is_word_guessed << '\n';
		file << DailyWord.daily_word << '\n';
	}


	file.close();
}


// IO_number -- reading and writing a string(date) to a file
std::string IO_string(const std::string& file_name, std::string content, FileOperation operation)
{
	std::fstream file;

	if (operation == FileOperation::Input)
	{
		file.open(file_name, std::ios::in);

		if (!file) return content;

		file >> content;
	}
	else
	{
		file.open(file_name, std::ios::out);

		if (!file) return content;

		file << content;
	}


	file.close();
	return content;
}


// IO_Stat -- reading and writing user statistics data to a file
void IO_Stat(const std::string& file_name, S_Stat& Statistic, bool is_first_launch, FileOperation operation)
{
	std::fstream file;

	if (operation == FileOperation::Input)
	{
		file.open(file_name, std::ios::in);

		if (!file) return;

		file >> Statistic.today_multiplier;
		file >> Statistic.yesterday_multiplier;
		file >> Statistic.average_multiplier;
	}
	else
	{
		file.open(file_name, std::ios::out);

		if (!file) return;

		file << Statistic.today_multiplier << '\n';
		file << Statistic.yesterday_multiplier << '\n';

		if (is_first_launch)
		{
			int result = get_average_multiplier(Statistic.today_multiplier, Statistic.yesterday_multiplier);
			file << result << '\n';
		}
		else  file << Statistic.average_multiplier << '\n';
	}


	file.close();
}


// IO_words -- reading and writing words to a file
void IO_words(const std::string& file_name, std::vector<std::string>& words,
	FileOperation operation, int words_countity)
{

	std::fstream file;

	if (operation == FileOperation::Input)
	{
		file.open(file_name, std::ios::in);

		if (!file) return;


		std::string line;
		words.reserve(words_countity);

		while (std::getline(file, line))
		{
			std::istringstream stream(line);
			std::string word;

			while (stream >> word)
			{
				words.push_back(line);
			}

		}
	}
	else
	{
		file.open(file_name, std::ios::out);

		if (!file) return;

		for (int i = 0; i < words.size(); i++)
		{
			file << words[i] << '\n';
		}
	}

	file.close();
}
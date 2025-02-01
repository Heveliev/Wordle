// IO_DailyWord.cpp -- reading and writing daily word data to file

#include <string>
#include <fstream>

#include "../../Config.h"

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
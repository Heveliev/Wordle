// IO_words.cpp -- reading and writing words to a file

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "../../Config.h"

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
// IO_Stat.cpp -- reading and writing user statistics data to a file

#include <string>
#include <fstream>

#include "../../Config.h"

#include "../../game_logic/get_average_multiplier/get_average_multiplier.h"

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
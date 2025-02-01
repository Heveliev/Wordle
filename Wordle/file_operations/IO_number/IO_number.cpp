// IO_number.cpp -- reading and writing a number to a file

#include <string>
#include <fstream>

#include "../../Config.h"

int IO_number(const std::string& file_name, int number, FileOperation operation)
{

	std::fstream file;

	

	if (operation == FileOperation::Input)
	{
		file.open(file_name, std::ios::in);

		if (!file) return number;

		file >> number;
	}
	else
	{
		file.open(file_name, std::ios::out);

		if (!file) return number;

		file << number;
	}


	file.close();
	return number;
}
#pragma once

#include <string>

#include "../../Config.h"

void IO_Stat(const std::string& file_name, S_Stat& statistic, bool is_first_launch = true, 
	FileOperation operation = FileOperation::Input);
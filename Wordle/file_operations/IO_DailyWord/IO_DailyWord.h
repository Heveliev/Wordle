#pragma once

#include <string>

#include "../../Config.h"

void IO_DailyWord(const std::string& file_name, S_DailyWord& DailyWord, FileOperation operation = FileOperation::Input);
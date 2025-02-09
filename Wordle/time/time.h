#pragma once

#include <string>

#include "../Config.h"

std::string get_today_utc();

bool is_same_day(const std::string& file_name);
// get_today_utc.cpp -- find out today's date

#include <ctime>

#include "../../Config.h"

int get_today_utc()
{
	int now = std::time(nullptr);
	return (now - (now % Config::TIME_COEFFICIENT));
}


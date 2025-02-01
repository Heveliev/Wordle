// is_same_day.cpp -- checking the start of a new day

#include <ctime>
#include <string>

#include "../../Config.h"

#include "../../file_operations/IO_number/IO_number.h"

#include "../get_today_utc/get_today_utc.h"

bool is_same_day(const std::string& file_name)
{
    int get_time_from_file = IO_number(file_name);
    int today = get_today_utc();

    if (get_time_from_file == today) return false;

    IO_number(file_name, today,FileOperation::Output);

    return true;
}
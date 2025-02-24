// time.cpp -- files for working with time

#include <ctime>
#include <string>

#include "../Config.h"

#include "../fileoperations/fileoperations.h"


// get_today_utc -- find out today's date
std::string get_today_utc()
{
    std::time_t now = std::time(nullptr);
    std::tm utc_time;

    if (gmtime_s(&utc_time, &now) != 0)
    {
        return "";
    }

    char date[15];

    std::strftime(date, sizeof(date), "%d-%m-%Y", &utc_time);

    return std::string(date);

}


// is_same_day -- checking the start of a new day
bool is_same_day(const std::string& file_name)
{
    std::string get_date_from_file = IO_string(file_name);
    std::string today_date = get_today_utc();

    if (get_date_from_file == today_date) return false;

    IO_string(file_name, today_date, FileOperation::Output);

    return true;
}
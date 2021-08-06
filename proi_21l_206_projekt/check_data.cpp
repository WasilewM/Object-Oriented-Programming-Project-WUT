#include "check_data.h"
#include "convert_str_to_int.h"

// function checks whether given string only consists of letters
// both uppercase and lower case letters are vaild
bool checkIfOnlyLetters(std::string to_be_checked)
{
    if(to_be_checked == "")
    {
        return false;
    }

    for (unsigned long i = 0; i < to_be_checked.length(); ++i)
    {
        // checking for lower case letters
        if (to_be_checked[i] >= 'a' && to_be_checked[i] <= 'z')
        {
            continue;
        }
        else
        {
            // checking for uppers case letters
            if (to_be_checked[i] >= 'A' && to_be_checked[i] <= 'Z')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}


// function checks whether given string is of an expected date format
// yyyy.mm.dd-hh:mm:ss
bool checkDateCorrectness(std::string date)
{
    std::string year = "";
    std::string month = "";
    std::string day = "";
    std::string hour = "";
    std::string minutes = "";
    std::string seconds = "";

    if (date.length() != 19)
    {
        return false;
    }

    // checking whether separating symbols are in correct places
    if (date[4] != '.' ||
        date[7] != '.' ||
        date[10] != '-' ||
        date[13] != ':' ||
        date[16] != ':')
    {
        return false;
    }

    // copying date values to separate string variables
    for (int i = 0; i < 4; ++i)
    {
        year += date[i];
    }

    for (int i = 5; i < 7; ++i)
    {
        month += date[i];
    }

    for (int i = 8; i < 10; ++i)
    {
        day += date[i];
    }

    for (int i = 11; i < 13; ++i)
    {
        hour += date[i];
    }

    for (int i = 14; i < 16; ++i)
    {
        minutes += date[i];
    }

    for (int i = 17; i < 19; ++i)
    {
        seconds += date[i];
    }

    // checking data correctness and covnerting the data
    std::pair <bool, int> converted_year = convert_str_to_int(year);
    std::pair <bool, int> converted_month = convert_str_to_int(month);
    std::pair <bool, int> converted_day = convert_str_to_int(day);
    std::pair <bool, int> converted_hour = convert_str_to_int(hour);
    std::pair <bool, int> converted_minutes = convert_str_to_int(minutes);
    std::pair <bool, int> converted_seconds = convert_str_to_int(seconds);

    // checking whether date values are as expected - not only numerical
    // but also in appriate range - for example days numbers in months
    if (
        converted_year.first && converted_year.second > 0 &&
        converted_month.first && converted_month.second > 0 &&
        converted_day.first && converted_day.second > 0 &&
        converted_hour.first && converted_hour.second > 0 &&
        converted_minutes.first && converted_minutes.second >= 0 &&
        converted_seconds.first && converted_seconds.second >= 0
        )
    {
        if (converted_month.second == 1 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 2 && converted_day.second > 28
            && converted_year.second % 4 != 0)
        {
            return false;
        }

        if (converted_month.second == 2 && converted_day.second > 29
            && converted_year.second % 4 == 0)
        {
            return false;
        }

        if (converted_month.second == 3 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 4 && converted_day.second > 30)
        {
            return false;
        }

        if (converted_month.second == 5 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 6 && converted_day.second > 30)
        {
            return false;
        }

        if (converted_month.second == 7 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 8 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 9 && converted_day.second > 30)
        {
            return false;
        }

        if (converted_month.second == 10 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second == 11 && converted_day.second > 30)
        {
            return false;
        }

        if (converted_month.second == 12 && converted_day.second > 31)
        {
            return false;
        }

        if (converted_month.second > 12)
        {
            return false;
        }

        if (converted_hour.second > 24)
        {
            return false;
        }

        if (converted_hour.second == 24 && converted_minutes.second != 0
            && converted_seconds.second != 0)
        {
            return false;
        }

        if (converted_minutes.second > 59)
        {
            return false;
        }

        if (converted_seconds.second > 59)
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

// function checls, whether given value is a valid position
bool checkPosition(std::string position)
{
    if (position == "captain" || position == "pilot"
        || position == "technician" || position == "assistant")
    {
        return true;
    }

    return false;
}
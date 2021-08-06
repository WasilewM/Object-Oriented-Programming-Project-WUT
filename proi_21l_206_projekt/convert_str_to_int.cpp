#include "convert_str_to_int.h"

// function checks whether string can be converted to int and if so
// converts it
std::pair <bool, int> convert_str_to_int(std::string option)
{
    bool if_correct = true;
    int numeric_option = 0;

    for (unsigned long i = 0; i < option.length(); ++i)
    {
        if (option[i] >= '0' && option[i] <= '9')
        {
            numeric_option = numeric_option * 10 + int(option[i] - '0');
        }
        else
        {
            if_correct = false;
            break;
        }
    }

    std::pair <bool, int> result = { if_correct, numeric_option };
    return result;
}
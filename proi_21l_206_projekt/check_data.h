#ifndef CHECK_DATA_H
#define CHECK_DATA_H
#include <string>

// function checks whether given string only consists of letters
// both uppercase and lower case letters are vaild
bool checkIfOnlyLetters(std::string to_be_checked);

// function checks whether given string is of an expected date format
// yyyy.mm.dd-hh:mm:ss
bool checkDateCorrectness(std::string date);

// function checls, whether given value is a valid position
bool checkPosition(std::string position);

#endif
#ifndef string_helper_h
#define string_helper_h

// including standard cpp headers
#include <vector>
#include <sstream>      // for converting a string to create a StringStream object
#include <iterator>

using namespace std;

// split given string with given delimiter
// extern keyword indicates that this function is declared but not defined in this file. It's meant to be defined in other file.
extern vector<std::string> split(const string &s, char delimiter);

#endif
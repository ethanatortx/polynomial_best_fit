#ifndef STRING_UTILTIY_H
#define STRING_UTILTIY_H

#include <string>
#include <vector>

std::vector<std::string> split_string(std::string s, const char delim);
std::vector<std::string> split_string(std::string s, const char delim, const char bounding);

#endif
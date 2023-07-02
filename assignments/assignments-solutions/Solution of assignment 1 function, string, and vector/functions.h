#ifndef functions_h
#define functions_h

#include <vector>
#include <string>

void print(const std::vector<std::string>& v);
std::vector<int> string_lengths(const std::vector<std::string>& v);
void print(const std::vector<int>& v);
std::string longest_string(const std::vector<std::string>& v);
std::string shortest_string(const std::vector<std::string>& v);
std::string alpha_first_string(const std::vector<std::string>& v);
std::string alpha_last_string(const std::vector<std::string>& v);
#endif
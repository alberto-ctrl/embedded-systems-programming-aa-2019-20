#ifndef FUNCRIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;

void print(const vector<string>&v);
void print(const vector<int>&v);
vector<int> string_lengths(const vector<string>&v);
string longest_string(const vector<string>&v);
string shortest_string(const vector<string>&v);
string alpha_first_string(vector<string> v);
string alpha_last_string(vector<string> v);

#endif

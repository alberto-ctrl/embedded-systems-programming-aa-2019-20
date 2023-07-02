// Stroustrup, Programming -- Principles and Practice Using C++ (Second Edition)
// Chapter 8, Exercise 13

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

#include "functions.h"

int main()
{
	vector<string> string_v;
	string_v.push_back("first");
	string_v.push_back("second");
	string_v.push_back("third");
	string_v.push_back("fourth");
	string_v.push_back("fifth");
	string_v.push_back("sixth");
	string_v.push_back("seventh");

	cout << "Vector of strings: \n";
	// 1. write a function "print" that prints the vector of strings
	print(string_v);

	// 2. write a function string_lengths returns a vector
	//    with length of each string in argument
	vector<int> lengths = string_lengths(string_v);

	cout << "Vector of lengths:\n";
	print(lengths);

	cout << "\nCheck for empty vectors\n";
	cout << "Empty vector\n"; 
	vector<string> empty_string_v;
	print(empty_string_v);
	vector<int> empty_lengths = string_lengths(empty_string_v);
	print(empty_lengths);
	cout << endl;
	

	// 3. write a function "longest_string" that
	//    returns longest string in a vector of strings
	cout << "Longest string: " << longest_string(string_v) << endl;

	// 4. write a function "shortest_string" that
	// returns the shortest string in a vector of strings
	cout << "Shortest string: " << shortest_string(string_v) << endl;

	// 5. write a function "alpha_first_string" that
	// returns lexicographically first string in a vector of strings
	cout << "Lexicographically first string: " << alpha_first_string(string_v) << endl;

	// 6. write a function "alpha_last_string" that
	// returns lexicographically last string in a vector of strings
	cout << "Lexicographically last string: " << alpha_last_string(string_v) << endl;

	return 0;
}

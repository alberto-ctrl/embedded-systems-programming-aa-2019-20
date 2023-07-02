#include "functions.h"

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <algorithm>
using std::sort;
using std::min_element;

void print(const vector<string>& v)
{
	if (!v.empty()) {
		vector<string>::const_iterator pos;
		cout << "{ ";
		for(pos = v.cbegin(); pos != v.cend(); ++pos)
			cout << *pos << " ";
		cout << " }" <<endl;
	} else {
		cout << "vector is empty\n";
	}
}

vector<int> string_lengths(const vector<string>& v)
{
	vector<int> lengths_vector;

	vector<string>::const_iterator pos;

	for(pos = v.cbegin(); pos != v.cend(); ++pos)
			lengths_vector.push_back((*pos).length());

	return lengths_vector;
}

void print(const vector<int>& v)
{
	if (!v.empty()) {
		vector<int>::const_iterator pos;
		cout << "{ ";
		for(pos = v.cbegin(); pos != v.cend(); ++pos)
			cout << *pos << " ";
		cout << " }" << endl;
	} else {
		cout << "vector is empty\n";
	}
}



//	There are several ways of writing a function that finds the longest string,
//  this is one of the simplest implementations.

//  You must deal with an empty vector argument, I decided to just signal an error and stop the program
//  because you should not work with empty vector
//  an alternative could be to return a -1 or something like that but the callers should be aware
//  of the meaning of -1

string longest_string(const vector<string>& v)
{
    if (v.size() == 0) {
		cerr << "longest_string(): argument is empty vector";
		exit(EXIT_FAILURE);
	}

    string longest;
    unsigned int max_length = 0;
    for (int i=0; i<static_cast<int>(v.size()); ++i) {
        if (v[i].length() > max_length) {
            max_length = v[i].length();
            longest = v[i];
        }
    }
    return longest;
}

// You could implement the following function as the previous one
// in the following an alternative (and more advanced) implementation
// using STL algorithm

string shortest_string(const vector<string>& v)
{
    if (v.size() == 0) {
		cerr << "shortest_string(): argument is empty vector";
		exit(EXIT_FAILURE);
	}

    string shortest;
	shortest = *min_element(v.begin(), v.end(),
                     [] (const string& s1, const string& s2) {
                         return s1.length() < s2.length(); }
                     );

    return shortest;
}

string alpha_first_string(const vector<string>& v)
{
	if (v.size() == 0) {
		cerr << "alpha_first_string(): argument is empty vector";
		exit(EXIT_FAILURE);
	}

    string alpha_first;
	alpha_first = *min_element(v.begin(), v.end());

    return alpha_first;
}


// You could implement the following function as the previous one
// with max_element instead of min_element
// in the following a less efficient alternative
// (you are required to order a new vector)
string alpha_last_string(const vector<string>& v)
{
	if (v.size() == 0) {
		cerr << "alpha_last_string(): argument is empty vector";
		exit(EXIT_FAILURE);
	}

	vector<string> ordered_v{v};
	sort(ordered_v.begin(), ordered_v.end());

	return ordered_v.back();
}

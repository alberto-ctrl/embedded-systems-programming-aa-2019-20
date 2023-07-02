#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
#include "functions.h"

void print(const vector<string>&v){
	cout << "{ ";
	for(int i=0; i<static_cast<int>(v.size()); ++i)
		cout << v[i] << " ";
	cout << "}\n";
}

void print(const vector<int>&v){
	cout << "{ ";
	for(int i=0; i<static_cast<int>(v.size()); ++i)
		cout << v[i] << " ";
	cout << "}\n";
}

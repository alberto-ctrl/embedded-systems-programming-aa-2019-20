#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
#include "functions.h"

vector<int> string_lengths(const vector<string>&v){
		vector<int> v_integers;

		for(int i=0; i<static_cast<int>(v.size()); ++i){
			string box{v[i]};
			v_integers.push_back(box.size());
		}

		return v_integers;
}

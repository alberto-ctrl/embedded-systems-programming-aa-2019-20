#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
#include "functions.h"

string alpha_last_string(vector<string> v){
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		return v[0];
}

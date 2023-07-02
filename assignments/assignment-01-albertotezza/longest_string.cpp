#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
#include "functions.h"

string longest_string(const vector<string>&v){
		size_t dim{0};
		string box_max;

		for(int i=0; i<static_cast<int>(v.size()); ++i){
			string box{v[i]};
				if(box.size()>dim){
					dim=box.size();
					box_max=box;
				}
		}
		return box_max;
}

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
#include "functions.h"

string shortest_string(const vector<string>&v){
	size_t dim{10};
	string box_min;
	vector<string>::const_iterator pos;

	for(pos=v.begin(); pos!=v.end(); ++pos){

				if((*pos).size()<dim){
					dim=(*pos).size();
					box_min=*pos;
				}
		}
		return box_min;
} // funziona con iteratori

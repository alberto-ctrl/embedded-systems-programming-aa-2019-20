// IOManagement.h

#ifndef IOManagement_h
#define IOManagement_h

#include "Car.h"

#include <string>
using std::string;
#include <fstream>
using std::ifstream;

void io_management(const int id);
ifstream opening(string file_name);
bool reading(ifstream &infile, Car& readed_car);
void closing(ifstream &infile);
int find_next_event();

#endif

// BookingManagement.h

#ifndef BookingManagement_h
#define BookingManagement_h

#include "Car.h"

#include <string>
using std::string;
#include <fstream>
using std::ifstream;

void booking_management();
ifstream opening(string file_name);
bool reading(ifstream& infile, Car& readed_booking, Car& car_in, Car& car_out);
void closing(ifstream &infile);
int find_next_event();

#endif

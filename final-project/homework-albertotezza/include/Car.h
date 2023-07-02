// Car.h

#ifndef Car_h
#define Car_h

#include "DateTime.h"

#include <ostream>
#include <string>
using std::string;


class Car
{
public:
	Car(); // default constructor
	Car(string license_plate, DateTime event); // constructor

	string license_plate() const { return license_plate_; }
	DateTime event() const { return event_; }

private:
	string license_plate_;
	DateTime event_;
};

std::ostream& operator<<(std::ostream& os, const Car& m);

#endif

// car.cpp

#include "Car.h"

#include <ostream>
#include <iostream>
using std::cerr;
#include <string>
using std::string;


// default constructor
Car::Car()
	:license_plate_{"-------"},
  event_{DateTime{}}
{}

// constructor
Car::Car(string license_plate, DateTime event)
  :license_plate_{license_plate},
  event_{event}
{
  // check for data provided by the input file
	if (license_plate.size()!=7)
	{
		cerr << "Car(): wrong informations about license_plate\n";
		exit(EXIT_FAILURE);
	}
}

// operators
std::ostream& operator<<(std::ostream& os, const Car& m)
{
	return os << m.event() << ' ' << m.license_plate();
}

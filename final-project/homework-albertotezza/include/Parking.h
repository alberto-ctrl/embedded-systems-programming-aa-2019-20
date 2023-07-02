// Parking.h

#ifndef Parking_h
#define Parking_h

#include "DateTime.h"
#include "Car.h"

#include <list>
using std::list;
#include <string>
using std::string;


class Parking {
public:
	Parking(); // default constructor
	Parking(string parking_name, int max_capacity); // constructor

	int max_capacity() const { return max_capacity_; }
	string parking_name() const { return parking_name_; }
	void add_car(const Car& to_manage);
	void remove_car(const Car& to_manage);
	int current_capacity() const { return current_capacity_; }
	void show_currently_parked();
	unsigned int number_of_currently_parked() const { return currently_parked_.size(); }

	void update_fee(const Car& to_manage);

	// functions utilized in bookings_management for reservations
	void increase_current_capacity() { ++current_capacity_; }
	void add_car_booked(const Car& to_manage);

	float total_gain() const { return total_gain_; };	// function utilized in test_parking_spaces.cpp

private:
	string parking_name_;
	int max_capacity_;
	int current_capacity_;				// number of cars currently parked (both parked cars and reservations are counted)
	list<Car> currently_parked_;	// container of Car with license plate + date and time information of cars currently in the Parking

	const float DAILY_FEE{5.0};		// fee for 1 day
	const float HOURLY_FEE{0.2};	// fee for 1 hour
	float car_gain_;
	float total_gain_;

	float fee_calculation(const DateTime& entry, const DateTime& exit);

};

#endif

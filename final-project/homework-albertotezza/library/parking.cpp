// parking.cpp

#include "Parking.h"

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <list>
using std::list;

// default constructor
Parking::Parking()
	:parking_name_{"-"},
  max_capacity_{1},
  current_capacity_{0},
	car_gain_{0},
	total_gain_{0}
{}

// constructor
Parking::Parking(string parking_name, int capacity)
  :parking_name_{parking_name},
  max_capacity_{capacity},
	current_capacity_{0},
	car_gain_{0},
	total_gain_{0}
{
  // check for data provided for parkings
	if (capacity<1)
	{
		cerr << "Parking(): wrong informations about parking capacity\n";
		exit(EXIT_FAILURE);
	}
}

// input const by reference: to_manage, Car type that must be added to the calling Parking variable
// output by video: Car added (include event date and time information)
void Parking::add_car(const Car& to_manage)
{
  currently_parked_.push_back(to_manage);
  ++current_capacity_;
  cout << to_manage << " IN " << parking_name() << endl;
}

// erase from the list<Car> currently_parked_ the element with the same license_plate_ of the passed value (if there isn't this, it does nothing)
// input const by reference: to_manage, Car type that must be removed to the Parking calling variable
// output by video: Car removed if occurred (include event date and time information)
void Parking::remove_car(const Car& to_manage)
{
  for (list<Car>::iterator it=currently_parked_.begin(); it!=currently_parked_.end(); ++it) {
		if ((*it).license_plate()==to_manage.license_plate()) {
      it=currently_parked_.erase(it);
      --current_capacity_;
      cout << to_manage << " OUT " << parking_name();
			cout << ' ' << car_gain_ << "€ " << total_gain_ << "€ " << endl;
      break;  // element found! you can terminate the loop
    }
  }
}

// function to show the list of cars currently in a parking
// output by video: list<Car> currently_parked_
void Parking::show_currently_parked()
{
  cout << "show_currently_parked() for " << parking_name() << ':' << endl;
  for (list<Car>::iterator it=currently_parked_.begin(); it!=currently_parked_.end(); ++it)
    cout << "\t\t "<< (*it).license_plate() << " entered on: " << (*it).event() << endl;
}


// function to calculate the price depending on the time spent by a car in the parking (called in: void Parking::update_fee(...))
// input const by reference: entry, DateTime type value associated to the date of the Car entry in a parking
// input const by reference: exit, DateTime type value associated to the date of the Car exit in a parking
// output by return: price calculated
float Parking::fee_calculation(const DateTime& entry, const DateTime& exit)
{
	int minutes_difference{(exit.date_hours_conv())-entry.date_hours_conv()+1}; // +1 so a prenotation will pay a full DAILY_FEE
	int days_difference{minutes_difference/(60*24)};
	int minutes_to_next_day{minutes_difference-(days_difference*60*24)};

	float price{days_difference*DAILY_FEE};
	price+=(minutes_to_next_day/60)*HOURLY_FEE;

	return price;
}

// function that calculate the fee based on the days and hours *completely* spent for a car in a parking ( + update the total_gain_ of calling Parking variable)
// input const by reference: to_manage, Car type that is coming out from the parking and need the price
// output by video: car_gain_ referred to the passed input, total gain of the calling Parking variable
void Parking::update_fee(const Car& to_manage)
{
	for (list<Car>::iterator it=currently_parked_.begin(); it!=currently_parked_.end(); ++it) {
		if ((*it).license_plate()==to_manage.license_plate()) {
			car_gain_=fee_calculation((*it).event(), to_manage.event());
			total_gain_+=car_gain_;
      break;  // element found! you can terminate the loop
    }
  }
}

// (similarly to void Parking::add_car(...))
// input const by reference: to_manage, Car type that must be added to the calling Parking variable
// output by video: Car added (include event date and time information)
void Parking::add_car_booked(const Car& to_manage)
{
  currently_parked_.push_back(to_manage);
	// ++current_capacity_; // OMITTED: this value has already been updated when the booking of this Car was accepted
	cout << to_manage << " IN " << parking_name() << endl;
}

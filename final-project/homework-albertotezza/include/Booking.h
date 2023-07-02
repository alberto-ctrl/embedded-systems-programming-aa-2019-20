// Booking.h

#ifndef Booking_h
#define Booking_h

#include "Car.h"

#include <list>
using std::list;

class Booking {
public:
	Booking(); // default constructor

	int current_booked() const { return current_booked_; }
	void add_booking(const Car& reservation, const Car& booking_start, const Car& booking_end);
	void sort_bookings();
	void remove_booking_start();
	void remove_booking_end();
	Car next_prenotation_in() const { return booking_start_.front(); }		// return the first elementi of the list
	Car next_prenotation_out() const { return booking_end_.front(); }
	bool booking_start_empty() const { return booking_start_.empty(); }		// to check if the list is empty
	bool booking_end_empty() const { return booking_end_.empty(); }

private:
	int current_booked_;
	list<Car> booking_start_;		// container of Car with license plate + booking start instant
	list<Car> booking_end_;			// container of Car with license plate + booking end instant

};

#endif

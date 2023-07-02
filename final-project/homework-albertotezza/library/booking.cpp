// Booking.cpp

#include "Booking.h"
#include "Car.h"

#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;

// default constructor
Booking::Booking()
  :current_booked_{0}
{}

// function to fill the list<Car> of booking start and the list<Car> of booking end
// input const by reference: reservation, Car type that contain the license_plate and the date and time informations of a booking
// input const by reference: booking_start, Car type with the informations of bookng start for fill the associated list
// input const by reference: booking_end, Car type with the informations of bookng start for fill the associated list
// output by video: booking and success report
void Booking::add_booking(const Car& reservation, const Car& booking_start, const Car& booking_end)
{
  booking_start_.push_back(booking_start);
  booking_end_.push_back(booking_end);
  ++current_booked_;
  cout << reservation << " <-booking made successfully!" << endl;
}

// function for the std::list::sort() (called in: void Booking::sort_bookings())
bool temporal_comparison(const Car& first, const Car& second)
{
  return (first.event().date_hours_conv() < second.event().date_hours_conv());
}

// function for sorting the list<Car> booking_start_ and the list<Car> booking_end_
void Booking::sort_bookings()
{
  booking_start_.sort(temporal_comparison);
  booking_end_.sort(temporal_comparison);
}

// function to remove the first element of the list<Car> booking_start_
void Booking::remove_booking_start()
{
  booking_start_.pop_front();
}

// function to remove the first element of the list<Car> booking_end_
void Booking::remove_booking_end()
{
  booking_end_.pop_front();
  --current_booked_;
}

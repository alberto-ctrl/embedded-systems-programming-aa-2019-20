// bookings_management.cpp

#include "BookingsManagement.h"
#include "GlobalVariables.h"
#include "Booking.h"

#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;
using std::unique_lock;

// constants to call the positions in the global vector of events
const int ID_BOOKING{4};
const int ID_CAR_ENTER{5};
const int ID_CAR_EXIT{6};

// function utilized by the threads that manage the parking reservations
void booking_management()
{
  ifstream infile;
  Car last{"-------",DateTime{99,12,31,23,59}};
  Car car_enter;    // variable for saving the license plate + booking start instant
  Car car_exit;     // variable for saving the license plate + booking end instant
  Booking B;

  // set some positions of global vector for manage the events at "last" to avoid problem choosing next event
  // (this because the filling of the vector in these positions is done only after a booking success)
  next_car.at(ID_CAR_ENTER)=last;
  next_car.at(ID_CAR_EXIT)=last;

  infile=opening("prenotazioni.txt");

  // boolean for save the result of reading function
  bool r{reading(infile, next_car.at(ID_BOOKING), car_enter, car_exit)};

  while ( r || !B.booking_start_empty() || !B.booking_end_empty() ) {

    // Critical Section
    unique_lock<mutex> mlock(mtx);

    while (find_next_event()!=ID_BOOKING && find_next_event()!=ID_CAR_ENTER && find_next_event()!=ID_CAR_EXIT) {
      ok_advance.notify_one();
      ok_advance.wait(mlock);
    }

    // Non Critical Section
    mlock.unlock();
    // find which position contain the minor event
    int id_won{find_next_event()};

    switch(id_won) {
    case ID_BOOKING:
            // discard the booking if the parking P1 is full (in current_capacity_ both parked cars and reservations are counted)
            if (P1.current_capacity() < P1.max_capacity()) {
              B.add_booking(next_car.at(ID_BOOKING), car_enter, car_exit);
              P1.increase_current_capacity();
            }
            B.sort_bookings();
            r=reading(infile, next_car.at(ID_BOOKING), car_enter, car_exit); // ok now we can read another line from input file
            break;
    case ID_CAR_ENTER:
            B.remove_booking_start();
            P1.add_car_booked(next_car.at(ID_CAR_ENTER));
            break;
    case ID_CAR_EXIT:
            B.remove_booking_end();
            fee_updating_B=true;  // it's time to updating the accounting situation due to Booked cars (Parking P1)
            mlock.lock();
            while (fee_updating_B) {
              ok_update_fee.notify_one();
              ok_update_fee.wait(mlock);
            }
            mlock.unlock();
            P1.remove_car(next_car.at(ID_CAR_EXIT));
            break;
    }

    // contidions to update the global vector for manage the events (setting at "last" to avoid deadlocks)
    if (B.booking_start_empty())
      next_car.at(ID_CAR_ENTER)=last;
    else
      next_car.at(ID_CAR_ENTER)=B.next_prenotation_in();

    if (B.booking_end_empty())
      next_car.at(ID_CAR_EXIT)=last;
    else
      next_car.at(ID_CAR_EXIT)=B.next_prenotation_out();

    if (!r)
      next_car.at(ID_BOOKING)=last;

  } // while end

  // to free the function payments_managements blocked to the previous value of next_car[ID_CAR_EXIT]
  ok_update_fee.notify_one();

  // to close the file
  closing(infile);
}

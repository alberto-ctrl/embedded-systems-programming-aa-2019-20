// main.cpp

// The main thread creates six threads:
// - 4 of these threads are for the parkings access and exit control
// - 1 thread is for updating of the accounting situation
// - 1 thread is for parking reservations

#include "IOManagement.h"
#include "PaymentsManagement.h"
#include "BookingsManagement.h"
#include "Parking.h"

#include <vector>
using std::vector;
#include <thread>
using std::thread;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;

// global variables for the parkings
Parking P1{"PARK1", 200};
Parking P2{"PARK2", 100};

vector<Car> next_car(7,Car());      // global vector for manage the events, initialized with default Car() data
mutex mtx;                          // global mutex
condition_variable ok_advance;
condition_variable ok_update_fee;

int main()
{

  thread input_P1{io_management, 0};
  thread output_P1{io_management, 1};
  thread input_P2{io_management, 2};
  thread output_P2{io_management, 3};

  thread fee{payments_managements};

  thread reservations{booking_management};

  input_P1.join();
  output_P1.join();
  input_P2.join();
  output_P2.join();

  fee.join();

  reservations.join();

   return 0;
}

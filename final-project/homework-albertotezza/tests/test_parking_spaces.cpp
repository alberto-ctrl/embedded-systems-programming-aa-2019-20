// test_parking_spaces.cpp


#include "IOManagement.h"
#include "PaymentsManagement.h"
#include "BookingsManagement.h"
#include "Parking.h"

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <thread>
using std::thread;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;

// global variables for the parkings
Parking P1{"PARK1", 50};
Parking P2{"PARK2", 20};

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

  cout << "test_parking_spaces started:" << endl;

  for(int i=1; i<11; ++i) {

      cout << "\n\t\t At " << i << "0% in parking P1: " << endl;
      cout << "\t\t the maximum capacity of parking is: " << P1.max_capacity() << endl;
      cout << "\t\t places currently occupied: " << P1.number_of_currently_parked() << endl;
      cout << "\t\t places currently reserved: " << P1.current_capacity()-P1.number_of_currently_parked() << endl;
      cout << "\t\t so the places free are: " << P1.max_capacity()-P1.current_capacity() << endl;

      cout << "\n\t\t At " << i << "0% in parking P2: " << endl;
      cout << "\t\t the maximum capacity of parking is: " << P2.max_capacity() << endl;
      cout << "\t\t places currently occupied: " << P2.number_of_currently_parked() << endl;
      cout << "\t\t places currently reserved: " << P2.current_capacity()-P2.number_of_currently_parked() << endl;
      cout << "\t\t so the places free are: " << P2.max_capacity()-P2.current_capacity() << endl;
      cout << endl;

      std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  input_P1.join();
  output_P1.join();
  input_P2.join();
  output_P2.join();

  fee.join();

  reservations.join();

   return 0;
}

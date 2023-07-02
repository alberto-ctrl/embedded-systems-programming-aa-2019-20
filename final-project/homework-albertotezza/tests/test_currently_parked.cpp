// test_currently_parked.cpp

#include "IOManagement.h"
#include "PaymentsManagement.h"
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

// to to discard the part of parking reservations
const int ID_BOOKING{4};
const int ID_CAR_ENTER{5};
const int ID_CAR_EXIT{6};

// global variables for the parkings
Parking P1{"PARK1", 20};
Parking P2{"PARK2", 20};

vector<Car> next_car(7,Car());    // global vector for manage the events, initialized with default Car() data
mutex mtx;                        // global mutex
condition_variable ok_advance;
condition_variable ok_update_fee;

int main()
{
  // to to discard the part of parking reservations
  Car last{"-------",DateTime{99,12,31,23,59}};
  next_car.at(ID_BOOKING)=last;
  next_car.at(ID_CAR_ENTER)=last;
  next_car.at(ID_CAR_EXIT)=last;

  thread input_P1{io_management, 0};
  thread output_P1{io_management, 1};
  thread input_P2{io_management, 2};
  thread output_P2{io_management, 3};

  thread fee{payments_managements};

  cout << "Test_currently_parked started:" << endl;

  // test Parking::show_currently_parked for parkings
  for(int i=1; i<11; ++i) {
      cout << "\t\t At " << i << "0%: " << endl;
      P1.show_currently_parked();
      cout << "\t\t At " << i << "0%: " << endl;
      P2.show_currently_parked();
      cout << endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }

  input_P1.join();
  output_P1.join();
  input_P2.join();
  output_P2.join();
  fee.join();

   return 0;
}

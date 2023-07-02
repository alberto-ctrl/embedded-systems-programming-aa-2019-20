// io_management.cpp

#include "IOManagement.h"
#include "GlobalVariables.h"

#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::endl;
#include <vector>
using std::vector;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;
using std::unique_lock;

const int D_H_CONV_MIN{46080};     // DateTime::date_hours_conv() representation of DateTime first{00 01 01 00 00}
const int D_H_CONV_MAX{53614079};  // DateTime::date_hours_conv() representation of DateTime last{99 12 31 23 59}

// function utilized by the threads that manage the flow of cars into and out of parkings
// input by value: id, thread's identification
void io_management(const int id)
{
    ifstream infile;
    Car last{"-------",DateTime{99,12,31,23,59}};

    // to open the file based on thread's id
    switch(id) {
    case 0:
            infile=opening("parcheggioUnoIngresso.txt");
            break;
    case 1:
            infile=opening("parcheggioUnoUscita.txt");
            break;
    case 2:
            infile=opening("parcheggioDueIngresso.txt");
            break;
    case 3:
            infile=opening("parcheggioDueUscita.txt");
            break;
    default:
            cerr << "Error in the identifier of the thread" << endl;
            exit(EXIT_FAILURE);
    }

    // reading phase start
    // until the end of the file. Fill directly the global vector for manage the events (passed by reference in function reading)
    while (reading(infile, next_car.at(id))) {

      // Critical Section
      unique_lock<mutex> mlock(mtx);

      // exit or passing the cycle only if thread's turn
      while (find_next_event()!=id) {
        ok_advance.notify_one();
        ok_advance.wait(mlock);
      }

      // Non Critical Section
      mlock.unlock();

      // different actions based on thread's id
      switch(id) {
      case 0:
              if (P1.current_capacity()<P1.max_capacity())
                P1.add_car(next_car.at(id));
              break;
      case 1:
              fee_updating_P1=true;   // it's time to updating the accounting situation of P1
              mlock.lock();
              while (fee_updating_P1) {
                ok_update_fee.notify_one();
                ok_update_fee.wait(mlock);
              }
              mlock.unlock();
              P1.remove_car(next_car.at(id));
              break;
      case 2:
              if (P2.current_capacity()<P2.max_capacity())
                P2.add_car(next_car.at(id));
              break;
      case 3:
              fee_updating_P2=true;   // it's time to updating the accounting situation of P2
              mlock.lock();
              while (fee_updating_P2) {
                ok_update_fee.notify_one();
                ok_update_fee.wait(mlock);
              }
              mlock.unlock();
              P2.remove_car(next_car.at(id));
              break;
      }
    } // while end

          // to avoid deadlocks in thread who have not finished yet with io_management
          next_car.at(id)=last;     // setting to "last" after a while cycle end of a function
          ok_advance.notify_one();  // free a thread blocked due to previous value

          // to free the function payments_managements at the end of threads that needed updating the accounting situation
          if (next_car.at(1).event().date_hours_conv()==D_H_CONV_MAX
                && next_car.at(3).event().date_hours_conv()==D_H_CONV_MAX)
            ok_update_fee.notify_one();

    // to close the file
    closing(infile);
}

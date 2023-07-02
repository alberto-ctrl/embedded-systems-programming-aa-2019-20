// payments_managment.cpp

#include "PaymentsManagement.h"
#include "GlobalVariables.h"

#include <vector>
using std::vector;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;
using std::unique_lock;

// booleans associated to threads that start the fee updating
bool fee_updating_P1{false};
bool fee_updating_P2{false};
bool fee_updating_B{false};

const int D_H_CONV_MAX{53614079};  // DateTime::date_hours_conv() representation of DateTime last{99 12 31 23 59}

// function utilized by the threads that manage the updating of accounting situation
void payments_managements()
{
  // cycle to indicate the duration of the function
  while ((next_car.at(1).event().date_hours_conv()<D_H_CONV_MAX)
          || (next_car.at(3).event().date_hours_conv()<D_H_CONV_MAX)
          || (next_car.at(6).event().date_hours_conv()<D_H_CONV_MAX)) {

      unique_lock<mutex> mlock(mtx);
      ok_update_fee.notify_one();
      ok_update_fee.wait(mlock);

      // update the fees for the parking P1
      if (fee_updating_P1) {
        P1.update_fee(next_car.at(1));
        fee_updating_P1=false;
      }
      // update the fees for the parking P2
      if (fee_updating_P2) {
        P2.update_fee(next_car.at(3));
        fee_updating_P2=false;
      }

      // update the fees for the booking B
      if (fee_updating_B) {
        P1.update_fee(next_car.at(6));
        fee_updating_B=false;
      }

      // to wake the thread that has requested the update
      ok_update_fee.notify_one();
  }
}

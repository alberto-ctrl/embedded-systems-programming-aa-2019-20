// find_next_event.cpp

#include "IOManagement.h"
#include "BookingsManagement.h"
#include "GlobalVariables.h"

#include <vector>
using std::vector;

const int D_H_CONV_MIN{46080};  // DateTime::date_hours_conv() representation of DateTime first{00 01 01 00 00}

// function for find the minimal DateTime of the vector<Car> next_car
// output by return: n, integer type that carry the position of the minor event (next event) in the the global vector for manage the events (next_car[])
int find_next_event() {
  int n{0};
  int min{(next_car.at(0)).event().date_hours_conv()};

  for (int i=0; i<static_cast<int>(next_car.size()); ++i) {
    if ((next_car.at(i)).event().date_hours_conv() < min) {
      min=(next_car.at(i)).event().date_hours_conv();
      n=i;
    }
  }

  // if this function find as minimum a default DateTime value then return -1
  if (min<D_H_CONV_MIN+1)
    return -1;

  return n;
}

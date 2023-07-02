// GlobalVariables.h

#ifndef GlobalVariables_H
#define GlobalVariables_H

#include "Parking.h"

#include <vector>
using std::vector;
#include <mutex>
using std::mutex;
#include <condition_variable>
using std::condition_variable;

// global variables for the parkings
extern Parking P1;
extern Parking P2;

extern vector<Car> next_car;            // global vector for manage the events
extern mutex mtx;                       // global mutex
extern condition_variable ok_advance;
extern condition_variable ok_update_fee;

// booleans associated to threads that start the fee updating
extern bool fee_updating_P1;
extern bool fee_updating_P2;
extern bool fee_updating_B;

#endif

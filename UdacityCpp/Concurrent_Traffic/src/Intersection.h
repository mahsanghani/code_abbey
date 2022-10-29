//
// Created by Ahsan Ghani on 2022-10-29.
//

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "TrafficLight.h"
#include "TrafficObject.h"
#include <future>
#include <memory>
#include <mutex>
#include <vector>

using namespace std;

class Street;
class Vehicle;

class WaitingVehicles {
public:
  int getSize();

  void pushBack(shared_ptr<Vehicle> vehicle, promise<void> &&promise);
  void permitEntryToFirstInQueue();

private:
  vector<shared_ptr<Vehicle>> vehicles_;
  vector<promise<void>> promises_;
  mutex mutex_;
};

#endif

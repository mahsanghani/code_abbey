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

class Intersection : public TrafficObject {
public:
  Intersection();

  void setIsBlocked(bool isBlocked);

  void addVehicleToQueue(shared_ptr<Vehicle> vehicle);
  void addStreet(shared_ptr<Street> street);
  vector<shared_ptr<Street>> queryStreets(shared_ptr<Street> incoming);
  void simulate();
  void vehicleHasLeft(shared_ptr<Vehicle> vehicle);
  bool trafficLightIsGreen();

private:
  void processVehicleQueue();

  TrafficLight traffic_light_;
  vector<shared_ptr<Street>> streets_;
  WaitingVehicles waiting_vehicles_;
  bool is_blocked_;
};

#endif

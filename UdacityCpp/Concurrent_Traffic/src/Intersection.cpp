//
// Created by Ahsan Ghani on 2022-10-29.
//
#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>

#include "Intersection.h"
#include "Street.h"
#include "Vehicle.h"

using namespace std;

int WaitingVehicles::getSize() {
  lock_guard<mutex> lock(mutex_);
  return vehicles_.size();
}

void WaitingVehicles::pushBack(shared_ptr<Vehicle> vehicle,
                               promise<void> &&promise) {
  lock_guard<mutex> lock(mutex_);
  vehicles_.push_back(vehicle);
  promises_.push_back(move(promise));
}

void WaitingVehicles::permitEntryToFirstInQueue() {
  lock_guard<mutex> lock(mutex_);
  auto firstPromise = promises_.begin();
  auto firstVehicle = vehicles_.begin();

  firstPromise->set_value();

  vehicles_.erase(firstVehicle);
  promises_.erase(firstPromise);
}
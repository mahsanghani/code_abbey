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
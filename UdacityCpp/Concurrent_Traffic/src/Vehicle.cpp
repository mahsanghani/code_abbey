//
// Created by Ahsan Ghani on 2022-10-31.
//
#include "Vehicle.h"
#include "Intersection.h"
#include "Street.h"
#include <iostream>
#include <random>

using namespace std;

Vehicle::Vehicle() {
  _currStreet = nullptr;
  _posStreet = 0.0;
  type_ = ObjectType::objectVehicle;
  _speed = 400; // m/s
}

void Vehicle::setCurrentDestination(shared_ptr<Intersection> destination) {
  _currDestination = destination;
  _posStreet = 0.0;
}

void Vehicle::simulate() {
  threads_.emplace_back(thread(&Vehicle::drive, this));
}

void Vehicle::drive() {
  unique_lock<mutex> lck(mtx_);
  cout << "Vehicle #" << id_ << "::drive: thread id = " << this_thread::get_id()
       << endl;
  lck.unlock();
  bool hasEnteredIntersection = false;
  double cycleDuration = 1;
  chrono::time_point<std::chrono::system_clock> lastUpdate;
}
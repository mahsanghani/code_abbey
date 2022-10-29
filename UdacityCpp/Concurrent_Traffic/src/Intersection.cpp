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

Intersection::Intersection() {
  type_ = ObjectType::objectIntersection;
  is_blocked_ = false;
}

void Intersection::addStreet(shared_ptr<Street> street) {
  streets_.push_back(street);
}

vector<shared_ptr<Street>>
Intersection::queryStreets(shared_ptr<Street> incoming) {
  vector<shared_ptr<Street>> outgoings;
  for (auto it : streets_) {
    if (incoming->getID() != it->getID()) {
      outgoings.push_back(it);
    }
  }
  return outgoings;
}

void Intersection::addVehicleToQueue(shared_ptr<Vehicle> vehicle) {
  unique_lock<mutex> lck(mtx_);
  cout << "Intersection #" << id_
       << "::addVehicleToQueue: thread id = " << this_thread::get_id() << endl;
  lck.unlock();

  promise<void> prmsVehicleAllowedToEnter;
  future<void> ftrVehicleAllowedToEnter =
      prmsVehicleAllowedToEnter.get_future();
  waiting_vehicles_.pushBack(vehicle, move(prmsVehicleAllowedToEnter));

  ftrVehicleAllowedToEnter.wait();
  lck.lock();
  cout << "Intersection #" << id_ << ": Vehicle #" << vehicle->getID()
       << " is granted entry." << endl;

  lck.unlock();

  if (traffic_light_.getCurrentPhase() == TrafficLightPhase::kRed) {
    traffic_light_.waitForGreen();
  }
}

void Intersection::vehicleHasLeft(shared_ptr<Vehicle> vehicle) {
  this->setIsBlocked(false);
}

void Intersection::setIsBlocked(bool isBlocked) { is_blocked_ = isBlocked; }

void Intersection::simulate() {
  traffic_light_.simulate();
  threads_.emplace_back(thread(&Intersection::processVehicleQueue, this));
}

void Intersection::processVehicleQueue() {
  while (true) {
    this_thread::sleep_for(chrono::milliseconds(1));
    if (waiting_vehicles_.getSize() > 0 && !is_blocked_) {
      this->setIsBlocked(true);
      waiting_vehicles_.permitEntryToFirstInQueue();
    }
  }
}

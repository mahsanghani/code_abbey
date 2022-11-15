//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

class Vehicle {
public:
  Vehicle(int id) : id_(id) {}
private:
  int id_;
};

class WaitingVehicles {
public:
  WaitingVehicles() {}

  void printSize() {
    mutex_.lock();
    cout << "# Vehicles = " << vehicles_.size() << endl;
    mutex_.unlock();
  }

  void pushBack(Vehicle &&v) {
    mutex_.lock();
    vehicles_.emplace_back(move(v));
    mutex_.unlock();
  }

private:
  vector<Vehicle> vehicles_;
  mutex mutex_;
};

int main() {
  shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  vector<future<void>> futures;

  for (int i = 0; i < 1000; i++) {
    Vehicle v(i);
    futures.emplace_back(
        async(launch::async, &WaitingVehicles::pushBack, queue, move(v)));
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });

  queue->printSize();

  return 0;
}
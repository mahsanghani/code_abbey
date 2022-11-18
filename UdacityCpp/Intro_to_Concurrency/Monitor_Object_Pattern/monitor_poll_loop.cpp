//
// Created by Ahsan Ghani on 2022-11-13.
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
  int getID() { return id_; }

private:
  int id_;
};

class WaitingVehicles {
public:
  WaitingVehicles() {}

  void printIDs() {
    lock_guard<mutex> my_lock(mutex_);
    for (auto &v : vehicles_) {
      cout << " Vehicle #" << v.getID() << " is now waiting in the queue."
           << endl;
    }
  }

  void pushBack(Vehicle &&v) {
    lock_guard<mutex> uLock(mutex_);
    cout << " Vehicle #" << v.getID() << " will be added to the queue" << endl;
    vehicles_.emplace_back(move(v));
    this_thread::sleep_for(chrono::milliseconds(800));
  }

private:
  vector<Vehicle> vehicles_;
  mutex mutex_;
};

int main() {
  shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

  cout << "Spawning threads..." << endl;
  vector<future<void>> futures;

  for (int i = 0; i < 10; i++) {
    Vehicle v(i);
    futures.emplace_back(
        async(launch::async, &WaitingVehicles::pushBack, queue, move(v)));
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });

  cout << "Collecting results..." << endl;
  queue->printIDs();

  return 0;
}

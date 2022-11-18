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
  WaitingVehicles() : num_vehicles_(0) {}

  int getNumVehicles() {
    lock_guard<mutex> u_lock(mutex_);
    return num_vehicles_;
  }

  bool dataIsAvailable() {
    lock_guard<mutex> my_lock(mutex_);
    return !vehicles_.empty();
  }

  Vehicle popBack() {
    lock_guard<mutex> u_lock(mutex_);
    Vehicle v = move(vehicles_.back());
    vehicles_.pop_back();
    --num_vehicles_;

    return v;
  }

  void pushBack(Vehicle &&v) {
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> u_lock(mutex_);
    cout << " Vehicle #" << v.getID() << " will be added to the queue" << endl;
    vehicles_.emplace_back(move(v));
    ++num_vehicles_;
  }

private:
  vector<Vehicle> vehicles_;
  mutex mutex_;
  int num_vehicles_;
};

int main() {
  shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  cout << "Spawning threads..." << endl;
  vector<future<void>> futures;

  for (int i = 0; i < 10; ++i) {
    Vehicle v(i);
    futures.emplace_back(
        async(launch::async, &WaitingVehicles::pushBack, queuee, move(v)));
  }

  cout << "Collecting results..." << endl;
  while (true) {
    if (queue->dataIsAvailable()) {
      Vehicle v = queue->popBack();
      cout << " Vehicle #" << v.getID() << " has been removed from the queue"
           << endl;

      if (queue->getNumVehicles() <= 0) {
        this_thread::sleep_for(chrono::milliseconds(200));
        break;
      }
    }
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); });
  cout << "Finished : " << queue->getNumVehicles()
       << " vehicle(s) left in the queue" << endl;

  return 0;
}
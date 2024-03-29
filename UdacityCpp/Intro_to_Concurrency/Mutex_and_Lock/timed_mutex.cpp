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
  int getID() { return id_; }

private:
  int id_;
};

class WaitingVehicles {
public:
  WaitingVehicles() {}

  void printSize() {
    mutex_.lock();
    cout << "#vehicles = " << vehicles_.size() << endl;
    mutex_.unlock();
  }

  void pushBack(Vehicle &&v) {
    for (size_t i = 0; i < 3; i++) {
      if (mutex_.try_lock_for(chrono::milliseconds(100))) {
        vehicles_.emplace_back(move(v));
        mutex_.unlock();
        break;
      } else {
        cout << "Error! Vehicle #" << v.getID()
             << " could not be added to the vector" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
      }
    }
  }

private:
  vector<Vehicle> vehicles_;
  timed_mutex mutex_;
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
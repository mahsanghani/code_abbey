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

  Vehicle popBack() {
    unique_lock<mutex> uLock(mutex_);
    cond_.wait(uLock, [this] { return !vehicles_.empty(); });

    Vehicle v = move(vehicles_.back());
    vehicles_.pop_back();

    return v;
  }

  void pushBack(Vehicle &&v) {
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> uLock(mutex_);

    cout << " Vehicle #" << v.getID() << " will be added to the queue" << endl;
    vehicles_.push_back(move(v));
    cond_.notify_one();
  }

private:
  mutex mutex_;
  condition_variable cond_;
  vector<Vehicle> vehicles_;
};

int main() {
  shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  cout << "Spawning threads..." << endl;
  vector<future<void>> futures;

  for (int i = 0; i < 10; ++i) {
    Vehicle v(i);
    futures.emplace_back(
        async(launch::async, &WaitingVehicles::pushBack, queue, move(v)));
  }

  cout << "Collecting results..." << endl;
  while (true) {
    Vehicle v = queue->popBack();
    cout << " Vehicle #" << v.getID() << " has been removed from the queue"
         << endl;
  }

  for_each(futures.begin(), futures.end(),
           [](future<void> &ftr) { ftr.wait(); })

          cout
      << "Finished!" << endl;

  return 0;
}
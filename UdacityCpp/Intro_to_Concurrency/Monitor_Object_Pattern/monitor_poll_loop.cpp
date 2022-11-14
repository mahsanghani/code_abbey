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

private:
  vector<Vehicle> vehicles_;
  mutex mutex_;
};

int main() { return 0; }
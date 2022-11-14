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

  void pushBack(Vehicle &&v) {}

private:
};

int main() { return 0; }
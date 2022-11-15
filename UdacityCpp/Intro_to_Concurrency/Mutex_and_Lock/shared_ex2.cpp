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

private:
  vector<Vehicle> vehicles_;
  mutex mutex_;
};

int main() { return 0; }
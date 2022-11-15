//
// Created by Ahsan Ghani on 2022-11-15.
//
#include <algorithm>
#include <future>
#include <iostream>
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
  WaitingVehicles() : tmp_vehicles_(0) {}

  void printSize() { cout << "# Vehicles = " << tmp_vehicles_ << endl; }

  void pushBack(Vehicle &&v) {
    int old_num = tmp_vehicles_;
    this_thread::sleep_for(chrono::milliseconds(1));
    tmp_vehicles_ = old_num + 1;
  }

private:
  int tmp_vehicles_;
  vector<Vehicle> vehicles_;
};

int main() { return 0; }

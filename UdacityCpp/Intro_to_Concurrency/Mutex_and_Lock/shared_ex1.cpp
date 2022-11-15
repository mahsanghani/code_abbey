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
private:
  int tmp_vehicles_;
  vector<Vehicle> vehicles_;
};

int main() { return 0; }

//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : _id(0) {}
  void addID(int id) { _id = id; }
  void printID() { cout << "Vehicle ID = " << _id << endl; }

private:
  int _id;
};

int main() {
  shared_ptr<Vehicle> v(new Vehicle);
  thread t = thread(&Vehicle::addID, v, 1);

  t.join();
  v->printID();
  return 0;
}
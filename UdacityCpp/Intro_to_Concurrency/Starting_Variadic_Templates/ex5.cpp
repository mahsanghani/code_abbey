//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : id_(0) {}
  void addID(int id) { id_ = id; }
  void printID() { cout << "Vehicle ID = " << id_ << endl; }

private:
  int id_;
};

int main() {
  shared_ptr<Vehicle v>(new Vehicle);
  thread t = thread(&Vehicle::addID, v, 2);

  t.join();
  v->printID();
  return 0;
}
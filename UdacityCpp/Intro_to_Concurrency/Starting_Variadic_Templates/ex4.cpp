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
  Vehicle v1, v2;
  thread t1 = thread(&Vehicle::addID, v1,
                     1); // pass by value, doesn't affect original thread
  thread t2 = thread(
      &Vehicle::addID, &v2,
      2); // pass by reference, change will also be visible in the main thread

  t1.join();
  t2.join();
  v1.printID();
  v2.printID();
  return 0;
}

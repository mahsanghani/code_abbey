//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle(int id) : id_(id) {}
  void operator()() { cout << "Vehicle object has been created." << endl; }

private:
  int id_;
};

int main() {
  thread t(Vehicle(1));
  cout << "Finishing work in main()!" << endl;
  t.join();
  return 0;
}
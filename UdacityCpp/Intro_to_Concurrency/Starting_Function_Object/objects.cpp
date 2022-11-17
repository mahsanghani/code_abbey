//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  void operator()() { cout << "Vehicle object has been created. \n" << endl; }
};

int main() {
  thread t1((Vehicle()));
  thread t2 = thread(Vehicle());
  thread t3 { Vehicle(); };

  cout << "Finished work in main function!" << endl;

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
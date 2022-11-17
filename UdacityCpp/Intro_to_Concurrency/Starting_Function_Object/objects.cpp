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

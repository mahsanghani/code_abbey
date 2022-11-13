//
// Created by Ahsan Ghani on 2022-11-11.
//
#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : id_(0), name_(new string("Default Name")) {
    cout << "Vehicle #" << id_ << " Default constructor called!" << endl;
  }

  Vehicle(int id, string name) : id_(id), name(new string(name)) {
    cout << "Vehicle #" << id_ << " Initializing constructor called!" << endl;
  }

private:
};
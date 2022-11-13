//
// Created by Ahsan Ghani on 2022-11-11.
//
#include <future>
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : id_(0) {
    cout << "Vehicle #" << id_ << " Default constructor called" << endl;
  }

  Vehicle(int id) : id_(id) {
    cout << "Vehicle #" << id_ << " initializing constructor called" << endl;
  }

  void setID(int id) { id_ = id; }

  int getID() { return id_; }

private:
  int id_;
};
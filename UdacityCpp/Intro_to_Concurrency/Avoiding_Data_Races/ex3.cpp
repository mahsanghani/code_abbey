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

  Vehicle(const Vehicle &src) {
    id_ = src.id_;
    if (src.name_ != nullptr) {
      name_ = new string;
      *name_ = *src.name_;
    }
    cout << "Vehicle #" << id_ << " Copy constructor called!" << endl;
  }

  Vehicle(Vehicle &&src) {
    id_ = src.getID();
    name_ = new string(src.getName());
    src.setID(0);
    src.setName("Default Name");
    cout << "Vehicle #" << id_ << " Move constructor called!" << endl;
  }

private:
};
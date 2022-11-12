//
// Created by Ahsan Ghani on 2022-11-11.
//
#include <future>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : id(0), name_(new std::string("Default Name")) {
    cout << "Vehicle #" << id_ << "Default constructor called" << endl;
  }

  Vehicle(int id, string name) : id_(id), name_(new string(name)) {
    cout << "Vehicle #" << id_ << "Initializing constructor called" << endl;
  }

  Vehicle(Vehicle &&src) : name_(move(src.name_)) {
    id_ = src.getID();
    src.setID(0);
  }

  void setID(int id) { id_ = id; }

  int getID() { return id_; }

  void setName(string name) { *name_ = name; }

  string getName() { return *name_; }

private:
  int id_;
  unique_ptr<string> name_;
};

int main() {
  Vehicle v0;
  Vehicle v1(1, "Vehicle 1");

  future<void> ftr = async([](Vehicle v) { v.setName("Vehicle 2"); }, move(v0));

  ftr.wait();
  cout << v0.getName() << endl;

  return 0;
}
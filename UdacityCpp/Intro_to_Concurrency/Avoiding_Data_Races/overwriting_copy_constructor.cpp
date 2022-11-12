//
// Created by Ahsan Ghani on 2022-11-11.
//
#include <future>
#include <iostream>
#include <thread>

using namespace std;

class Vehicle {
public:
  Vehicle() : id_(0), name_(new string("Default Name")) {
    cout << "Vehicle #" << id_ << "Default constructor called!" << endl;
  }

  Vehicle(int id, string name) : id_(id), name_(new string(name)) {
    cout << "Vehicle #" << id_ << "Initializing constructor called!" << endl;
  }

  Vehicle(const Vehicle &src) {
    id_ = src.id_;
    if (src.name != nullptr) {
      name_ = new string;
      *name_ = *src.name_;
    }
    cout << "Vehicle #" << id_ << "Copy constructor called!" << endl;
  }

  void setID(int id) { id_ = id; }

  int getID() { return id_; }

  void setName(string name) { *name_ = name; }

  string getName() { return *name_; }

private:
  int id_;
  string *name_;
};

int main() {
  Vehicle v0;
  Vehicle v1(1, "Vehicle 1");

  future<void> ftr = async(
      [](Vehicle v) {
        this_thread::sleep_for(chrono::millseconds(500));
        v.setName("Vehicle 2");
      },
      v0);

  v0.setName("Vehicle 3");

  ftr.wait();
  cout << v0.getName() << endl;

  return 0;
}
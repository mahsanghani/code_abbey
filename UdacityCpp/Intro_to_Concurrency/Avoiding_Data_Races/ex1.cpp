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

int main() {
  Vehicle v0;
  Vehicle v1(1);

  future<void> ftr = async(
      [](Vehicle v) {
        this_thread::sleep_for(chrono::milliseconds(500));
        v.setID(2);
      },
      v0);

  v0.setID(3);

  ftr.wait();
  cout << "Vehicle #" << v0.getID() << endl;

  return 0;
}
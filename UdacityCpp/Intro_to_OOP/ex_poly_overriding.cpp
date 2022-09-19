//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>

using namespace std;

class Base_Class {
public:
  virtual void PrintVirtual() {
    cout << "This is a message from the base class!" << endl;
  }

  void Print() { cout << "This displays the base class." << endl; }
};

class Derived_Class : public Base_Class {
public:
  void PrintVirtual() {
    cout << "This is a message from the derived class!" << endl;
  }

  void Print() { cout << "This displays the derived class." << endl; }
};

int main() {
  Base_Class *pointer;
  Derived_Class der;
  pointer = &der;

  pointer->PrintVirtual();

  pointer->Print();
}
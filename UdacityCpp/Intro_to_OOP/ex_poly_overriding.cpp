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
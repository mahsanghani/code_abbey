//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>

using namespace std;

class Base {
public:
  Base(){};
  void virtual Print() = 0;
  void calc();
};

class Derived : public Base {
public:
  Derived(){};
  void Print();
  void calc();
};

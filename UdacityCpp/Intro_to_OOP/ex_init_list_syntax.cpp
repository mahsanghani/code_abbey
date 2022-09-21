//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>
#include <string>

using namespace std;

class InitList {
public:
  InitList(int &_ref, char _c) : ref(_ref), c(_c) {}
  void print() { std::cout << ref << " " << c << "\n"; }

private:
  int &ref;
  const char c;
};
//
// Created by Ahsan Ghani on 2022-09-28.
//
#include <iostream>

using namespace std;

class Abstraction {
private:
  int number;
  char character;

public:
  void static PrintCharAsNumber(char c);
  void static PrintNumberPlusOne(int num);
};
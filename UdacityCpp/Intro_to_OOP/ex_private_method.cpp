//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>

class Abstraction {
public:
  void SetAttributes(int number, char character);
  void GetAttributes();

private:
  int number_;
  char character_;
  void ProcessAttributes();
};
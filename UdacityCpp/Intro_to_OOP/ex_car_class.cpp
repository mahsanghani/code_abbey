//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
  int hp;
  int wt;
  char *brand;
  // char*, dynamic char array

public:
  int getHorsepower() const;
  int getWeight() const;
  string getBrand() const;

  void setHorsepower(int);
  void setWeight(int);
  void setBrand(string);
};

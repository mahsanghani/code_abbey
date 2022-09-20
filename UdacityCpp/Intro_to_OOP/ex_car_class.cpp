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

void Car::setHorsepower(int hp) { this->hp = hp; }

void Car::setWeight(int wt) { this->wt = wt; }

void Car::setBrand(string brand) {
  this->brand = new char[brand.length() + 1] strcpy(this->brand, brand.c_str());
}

int Car::getHorsepower() const { return this->hp; }

int Car::getWeight() const { return this->wt; }

string Car::getBrand() const {
  string brand_res;
  return brand_res + this->brand;
}
//
// Created by Ahsan Ghani on 2022-09-16.
//
#include "car.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<Car *> car_vect;
  Car *cp = nullptr;

  vector<string> colours{"red", "blue", "green"};

  for (int i = 0; i < 100; i++) {
    cp = new Car(colours[i % 3], i + 1);
    car_vect.push_back(cp);
  }

  for (Car *cp : car_vect) {
    cp->IncrementDistance();
  }

  for (Car *cp : car_vect) {
    cp->PrintCarData();
  }
}
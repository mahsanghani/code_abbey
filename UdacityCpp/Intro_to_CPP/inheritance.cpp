//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <iostream>
#include <string>

using namespace std;

class Car {
public:
  void PrintCarData() {
    cout << "The distance that the " << color << " car " << number
         << " has traveled is: " << distance << endl;
  }

  void IncrementDistance() { distance++; }

  Car(string c, int n) {
    color = c;
    number = n;
  }

private:
  string color;
  int distance = 0;
  int number;
};

class Sedan : public Car {
public:
  Sedan(string color, int number, string brand, string model, string trim)
      : Car(color, number), brand(brand), model(model), trim(trim) {
    cout << "Sedan Initialized Successfully!" << endl;
  }

private:
  string brand;
  string model;
  string trim;
};

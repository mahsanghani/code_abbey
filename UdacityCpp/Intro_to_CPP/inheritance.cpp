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
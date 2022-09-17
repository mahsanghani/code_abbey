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

class Truck : public Car {
public:
  Truck(string brand, string model, string trim)
      : brand(brand), model(model), trim(trim) {
    cout << "Truck Initialized Successfully!" << endl;
  }

private:
  string brand;
  string model;
  string trim;
};

int main() {
  Car car1 = Car("green", 1);
  Car car2 = Car("blue", 2);
  Car car3 = Car("green", 3);
  Car car4 = Car("red", 4);

  Sedan sedan1 = Sedan("gray", 1, "BMW", "3", "330i");
  Sedan sedan2 = Sedan("blue", 2, "Benz", "C", "C300");

  Truck truck1 = Truck("Ford", "F-150", "Raptor");

  car1.IncrementDistance();
  car2.IncrementDistance();
  car3.IncrementDistance();
  car4.IncrementDistance();

  car1.PrintCarData();
  car2.PrintCarData();
  car3.PrintCarData();
  car4.PrintCarData();
}
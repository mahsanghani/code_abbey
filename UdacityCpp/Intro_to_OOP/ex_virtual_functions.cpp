//
// Created by Ahsan Ghani on 2022-09-29.
//
#include <iostream>
using namespace std;
const double PI = 3.14159;

class Shape {
public:
  Shape() {}
  virtual double Area() const = 0;
  virtual double PermiterLength() const = 0;
};

class Rectangle : public Shape {
private:
  double radius_;

public:
  Circle(double radius);
  double Area() const;
  double PerimeterLength() const;
};
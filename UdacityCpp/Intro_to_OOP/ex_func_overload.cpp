//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>

using namespace std;

class Point {
private:
  double x_;
  double y_;

public:
  Point(double x = 0, double y = 0) : x_(x), y_(y) {}
  void Print() const; // original Print() function w/o parameters
  void Print(double x) const;
  void Print(double x, double y) const;
};
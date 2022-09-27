//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>

using namespace std;

class Point {
private:
  double x_;
  double y_;

public:
  Point(double x = 0, double y = 0) : x_(x), y_(y) {}

  Point operator+(Point const &pt);

  void Print();
};

Point Point::operator+(const Point &pt) {
  this->x_ = pt.x_;
  this->y_ = pt.y_;

  return *this;
}

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

void Point::Print() {
  cout << '(' << this->x_ << ", " << this->y_ << ")" << endl;
}

int main() {
  Point pt(1.5, 2.5);
  Point another_pt(1, -1);

  pt = pt + another_pt;

  cout << "current point: " << endl;
  pt.Print();

  return 0;
}

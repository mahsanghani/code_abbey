//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>
#include <string>

using namespace std;

class Line {
protected:
  double length_;
};

class Circle : public Line {
public:
  double getArea() const;
  void setRadius(double radius);
};

const double PI = 3.14159;

double Circle::getArea() const { return this->length_ * this->length_ * PI; }

void Circle::setRadius(double radius) { this->length_ = radius; }
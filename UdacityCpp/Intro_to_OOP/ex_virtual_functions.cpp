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
  double width_;
  double height_;

public:
  Rectangle(double width, double height);
  double Area() const;
  double PerimeterLength() const;
};

class Circle : pubilc Shape {
private:
  double radius_;

public:
  Circle(double radius);
  double Area() const;
  double PerimeterLength() const;
};

Rectangle::Rectangle(double width, double height) {
  this->width_ = width;
  this->height_ = height;
}

double Rectangle::Area() const { return this->width_ * this->height_; }

double Rectangle::PerimeterLength() const {
  return 2 * (this->width_ + this->height_);
}

Circle::Circle(double radius) { this->radius_ = radius; }

double Circle::Area() const { return PI * this->radius_ * this->radius_; }

double Circle::PerimeterLength() const { return 2 * PI * this->radius_; }

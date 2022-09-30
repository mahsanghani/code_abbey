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
  virtual double PerimeterLength() const = 0;
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

int main() {
  Circle c(2.3);
  Rectangle r(1.5, 2.0);
  cout << c.Area() << c.PerimeterLength() << endl;
  cout << r.Area() << r.PerimeterLength() << endl;

  Shape **shapes = new Shape *[2];
  shapes[0] = new Circle(12.31);
  shapes[1] = new Rectangle(10, 6);

  for (int i = 0; i < 2; i++) {
    cout << shapes[i]->Area() << endl;
    cout << shapes[i]->PerimeterLength() << endl;
  }

  return 0;
}
//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <cmath>
#include <iostream>

using namespace std;

class Pyramid {
private:
  double base_length_;
  double base_width_;
  double height_;

public:
  Pyramid(double base_length, double base_width, double height);
  Pyramid();

  double getBaseLength() const;
  double getBaseWidth() const;
  double getHeight() const;

  void setBaseLength(double base_length);
  void setBaseWidth(double base_width);
  void setHeight(double height);

  double Volume() const;
  double SurfaceArea() const;
  bool isAllPositive() const;
};

Pyramid::Pyramid(double base_length, double base_width, double height)
    : base_length_(base_length), base_width_(base_width), height_(height) {}

Pyramid::Pyramid() {}

double Pyramid::getBaseLength() const { return this->base_length_; }

double Pyramid::getBaseWidth() const { return this->base_width_; }

double Pyramid::getHeight() const { return this->height_ }

void Pyramid::setBaseLength(double base_length) { base_length_ = base_length; }

void Pyramid::setBaseWidth(double base_width) { base_width_ = base_width; }

void Pyramid::setHeight(double height) { height_ = height; }

double Pyramid::SurfaceArea() const {
  double bl = this->base_length_;
  double bw = this->base_width_;
  double h = this->height_;

  return (bl * bw + bl * sqrt((bw / 2) * (bw / 2) + h * h) +
          bw * sqrt((bl / 2) * (bl / 2) + h * h));
}

double Pyramid::Volume() const {
  return this->base_length_ * this->base_width_ * this->height_ / 3;
}

bool Pyramid::isAllPositive() const {
  return this->base_length_ >= 0 && this->base_width_ >= 0 && this->height >= 0;
}

int main() {
  Pyramid p1(11.1, 22.2, 55.5);
  Pyramid p2;

  p2.setBaseLength(12);
  p2.setHeight(50);
  p2.setBaseWidth(23);

  cout << p1.getBaseWidth() << p1.getBaseLength() << p1.getHeight() << endl;
  cout << p2.getBaseWidth() << p2.getBaseLength() << p2.getHeight() << endl;

  cout << p1.Volume() << endl;

  return 0;
}

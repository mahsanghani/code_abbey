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
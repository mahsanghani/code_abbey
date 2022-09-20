//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>

using namespace std;

class Rectangle;

class Square {
  friend class Rectangle;

private:
  double side;

public:
  Square(double square_side);
};

Square::Square(double square_side) { this->side = square_side; }

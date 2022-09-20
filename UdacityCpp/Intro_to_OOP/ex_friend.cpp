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

class Rectangle {
private:
  double rw;
  double rh;

public:
  double Rec_Area() const;
  void Convert_SquToRec(Square sq);
};

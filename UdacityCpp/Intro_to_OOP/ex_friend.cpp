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

double Rectangle::Rec_Area() const { return this->rw * this->rh; }

void Rectangle::Convert_SquToRec(Square sq) {
  this->rw = sq.side;
  this->rh = sq.side;
}

int main() {
  Square sq(3.3);
  Rectangle rec;
  rec.Convert_SquToRec(sq);
  cout << "The rectangle has an area of : " << rec.Rec_Area() << endl;
}

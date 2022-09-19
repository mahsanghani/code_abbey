//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>

class Abstraction {
private:
  int var1_;
  double var2_;

public:
  Abstraction(int var1, double var2);
  void printVal();
};

Abstraction::Abstraction(int var1, double var2) : var1_(var1), var2_(var2){};

void Abstraction::printVal() {
  cout << "var1 = " << this->var1_ << " var2 = " << this->var2_ << endl;
}

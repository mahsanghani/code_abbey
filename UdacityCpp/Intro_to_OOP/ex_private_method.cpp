//
// Created by Ahsan Ghani on 2022-09-27.
//
#include <iostream>

class Abstraction {
public:
  void SetAttributes(int number, char character);
  void GetAttributes();

private:
  int number_;
  char character_;
  void ProcessAttributes();
};

void Abstraction::SetAttributes(int number, char character) {
  this->number_ = number;
  this->character_ = character;
}

void Abstraction::GetAttributes() {
  this->ProcessAttributes();
  cout << this->number_ << endl << this->character_ << endl;
}

void Abstraction::ProcessAttributes() {
  number_ *= 6;
  character_ += 1;
}

int main() {
  Abstraction abs;
  abs.SetAttributes(5, 'c');
  abs.GetAttributes();

  return 0;
}

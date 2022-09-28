//
// Created by Ahsan Ghani on 2022-09-28.
//
#include <iostream>

using namespace std;

class Abstraction {
private:
  int number;
  char character;

public:
  void static PrintCharAsNumber(char c);
  void static PrintNumberPlusOne(int num);
};

void Abstraction::PrintCharAsNumber(char c) {
  int result = c;
  cout << result << endl;
}

void Abstraction::PrintNumberPlusOne(int num) {
  num++;
  cout << num << endl;
}

int main() {
  char c = 'x';
  int one = 1;

  Abstraction::PrintCharAsNumber(c);
  Abstraction::PrintNumberPlusOne(one);
}

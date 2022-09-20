//
// Created by Ahsan Ghani on 2022-09-19.
//
#include <iostream>

using namespace std;

template <class T> T ReturnMax(T a, T b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int num1 = 50;
  int num2 = 10;

  int res = ReturnMax(num1, num2);
  cout << "Bigger one is: " << res << endl;

  double n1 = 45.65;
  double n2 = 100.45;

  double res2 = ReturnMax(n1, n2);
  cout << "Bigger on is: " << res2 << endl;

  char char1 = 'c';
  char char2 = 'y';

  char char3 = ReturnMax(char1, char2);
  cout << "Bigger one is: " << char3 << endl;
}
//
// Created by Ahsan Ghani on 2022-09-20.
//
#include <iostream>

using namespace std;

template <typename _Tf> _Tf Average(const _Tf &num1, const _Tf &num2) {
  return (num1 + num2) / 2;
}

int main() {
  int int1 = 1, int2 = 2;
  std::cout << "The average of int1 and int2 is: " << Average(int1, int2)
            << std::endl;
  double double1 = 1.0, double2 = 2.3;
  std::cout << "The average of double1 and double2 is: "
            << Average(double1, double2) << std::endl;
  char char1 = 'a', char2 = 'z';
  std::cout << "The average of char1 and char2 is: " << Average(char1, char2)
            << std::endl;
}
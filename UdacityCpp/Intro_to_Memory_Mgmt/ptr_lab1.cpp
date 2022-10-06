//
// Created by Ahsan Ghani on 2022-10-04.
//
#include <iostream>

int main() {
  int *ptr;
  ptr = new int;
  *ptr = 25;
  std::cout << ptr << std::endl;
  std::cout << *ptr << std::endl;
  delete ptr;
  return 0;
}
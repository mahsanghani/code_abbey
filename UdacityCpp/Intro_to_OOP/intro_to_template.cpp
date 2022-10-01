//
// Created by Ahsan Ghani on 2022-10-01.
//
#include <iostream>

using namespace std;

template <typename T, typename U = char> class A {
public:
  T x;
  U y;
  A() {
    std::cout << "Constructor Called"
              << "\n";
  }
};

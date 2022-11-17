//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>

using namespace std;

int main() {
  int id = 0;
  auto f = [](const int id) { cout << "ID = " << id << endl; };

  f(id);

  return 0;
}
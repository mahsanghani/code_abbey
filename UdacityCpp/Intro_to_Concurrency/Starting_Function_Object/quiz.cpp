//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>

using namespace std;

int main() {
  int id = 0;

  auto f0 = [&id]() { cout << "ID in Lambda = " << id << endl; };

  auto f1 = [id]() mutable { cout << "ID in Lambda = " << id << endl; };
  f1();
  cout << "ID in Main = " << id << endl;

  auto f2 = [&id]() mutable { cout << "ID in Lambda = " << id << endl; };
  f2();
  cout << "ID in Main = " << id << endl;

  auto f3 = [](const int id) { cout << "ID in Lambda = " << id << endl; };
  f2(++id);

  f0();

  return 0;
}
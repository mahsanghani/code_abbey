//
// Created by Ahsan Ghani on 2022-11-16.
//
#include <iostream>

using namespace std;

int main() {
  int id = 0;

  id++;
  auto f1 = [id]() { cout << "ID = " << id << endl; };

  id++;
  auto f2 = [&id]() { cout << "ID = " << id << endl; };

  id++;
  //  auto f3 = [id]()
  //  {
  //    cout << "ID = " << ++id << endl;
  //  };

  id++;
  auto f4 = [id]() mutable { cout << "ID = " << id << endl; };

  id++;
  auto f5 = [&id]() mutable { cout << "ID = " << id << endl; };
}
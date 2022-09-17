//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string a("1 2 3");

  istringstream my_stream(a);

  int n;
  my_stream >> n;
  cout << n << endl;
}
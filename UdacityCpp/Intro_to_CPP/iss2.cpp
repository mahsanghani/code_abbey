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

  while (my_stream >> n) {
    cout << "That stream was successful: " << n << endl;
  }
  cout << "The stream has failed." << endl;
}
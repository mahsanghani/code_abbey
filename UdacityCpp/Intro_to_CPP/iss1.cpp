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

  while (my_stream) {
    my_stream >> n;
    if (my_stream) {
      cout << "That stream was successful: " << n << endl;
    } else {
      cout << "That stream was NOT successful!" << endl;
    }
  }
}
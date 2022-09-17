//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string b("1,2,3")

      istringstream my_stream(b);

  char c;
  int n;

  while (my_stream >> n >> c) {
    cout << "That stream was successful: " << n << " " << c << endl;
  }
  cout << "The stream has failed." << endl;
}
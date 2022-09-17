//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> ParseLine(string line) {
  istringstream line_stream(line);

  char c;
  int n;
  vector<int> vec;
  while (line_stream >> n >> c) {
    vec.push_back(n);
  }
  return vec;
}

//
// Created by Ahsan Ghani on 2022-09-16.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { kEmpty, kObstacle };

vector<int> ParseLine(string line) {
  istringstream sline(line);
  int n;
  char c;
  vector<int> row;
  while (sline >> n >> c && c == ',') {
    row.push_back(n);
  }
  return row;
}

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

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile(path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

string CellString(State state) {
  switch (state) {
  case State::kEmpty:
    cout << "0  ";
    break;
  case State::kObstacle:
    cout << "⛰  ";
    break;
  }

  switch (state) {
  case State::kObstacle:
    return "⛰  ";
  default:
    return "0  ";
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}
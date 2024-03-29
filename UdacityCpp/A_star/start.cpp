//
// Created by Ahsan Ghani on 2022-10-23.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { kEmpty, kObstacle };

vector<State> ParseLine(string line) {
  istringstream sline(line);
  int n;
  char c;
  vector<State> row;

  while (sline >> n >> c && c == ".") {
    if (n == 0) {
      row.push_back(State::kEmpty);
    } else {
      row.push_back(State::kObstacle);
    }
  }
  return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile(path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

vector<vector<State>> Search(vector<vector<State>> board, int start[],
                             int goal[]) {
  cout << "No path found!" << std::endl;
  return std::vector<vector<State>>{};
}

string CellString(State cell) {
  switch (cell) {
  case State::kObstacle:
    return "⛰   ";
  default:
    return "0   ";
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  int init[2] = {0, 0};
  int goal[2] = {4, 5};
  auto board = ReadBoardFile("1.board");
  vector<vector<State>> solution = Search(board, init, goal);
  PrintBoard(solution);
}

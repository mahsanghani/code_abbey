//
// Created by Ahsan Ghani on 2022-10-23.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line) {
  istringstream sline(line);
  int n;
  char c;
  vector<State> row;
  while (sline >> n >> c && c == ',') {
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

bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3];
  int f2 = b[2] + b[3];
  return f1 > f2;
}

void CellSort(vector<vector<int>> *v) { sort(v->begin(), v->end(), Compare); }

int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist,
               vector<vector<State>> &grid) {
  openlist.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

void ExpandNeighbors(const vector<int> &current, int goal[2],
                     vector<vector<int>> &openlist,
                     vector<vector<State>> &grid) {
  // Get current node's data.
  int x = current[0];
  int y = current[1];
  int g = current[2];

  // Loop through current node's potential neighbors.
  for (int i = 0; i < 4; i++) {
    int x2 = x + delta[i][0];
    int y2 = y + delta[i][1];

    // Check that the potential neighbor's x2 and y2 values are on the grid and
    // not closed.
    if (CheckValidCell(x2, y2, grid)) {
      // Increment g value and add neighbor to open list.
      int g2 = g + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openlist, grid);
    }
  }
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2],
                             int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open{};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    // Get the next node
    CellSort(&open);
    auto current = open.back();
    open.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      // Set the init grid cell to kStart, and
      // set the goal grid cell to kFinish before returning the grid.
      grid[init[0]][init[1]] = State::kStart;
      grid[goal[0]][goal[1]] = State::kFinish;
      return grid;
    }

    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }

  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!"
       << "\n";
  return std::vector<vector<State>>{};
}

string CellString(State cell) {
  switch (cell) {
  case State::kObstacle:
    return "⛰   ";
  case State::kPath:
    return "🚗   ";
  case State::kStart:
    return "🚦   ";
  case State::kFinish:
    return "🏁   ";
  default:
    return "0   ";
  }
}
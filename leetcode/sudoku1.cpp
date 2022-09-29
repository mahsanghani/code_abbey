//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<set<int>> rows(9);
    vector<set<int>> cols(9);
    vector<set<int>> cubes(9);

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }

        int current = board[i][j] - '0';

        if (rows[i].count(current) || cols[j].count(current) ||
            cubes[(i / 3) * 3 + j / 3].count(current)) {
          return false;
        }

        rows[i].insert(current);
        cols[j].insert(current);
        cubes[(i / 3) * 3 + j / 3].insert(current);
      }
    }

    return true;
  }
};
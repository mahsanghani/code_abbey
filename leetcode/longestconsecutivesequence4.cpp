//
// Created by Ahsan Ghani on 2022-09-29.
//
class Solution {
public:
  int dfs(map<int, int> &m, int i) {
    int result = 0;
    if (m.find(i + 1) != m.end() && m[i + 1] == 0) {
      m[i + 1] = 1;
      result += 1 + dfs(m, i + 1);
    }
    if (m.find(i - 1) != m.end() && m[i - 1] == 0) {
      m[i - 1] = 1;
      result += 1 + dfs(m, i - 1);
    }

    return result;
  }

  int longestConsecutive(vector<int> &nums) {
    map<int, int> m;
    int result = 1;
    for (int i : nums) {
      m[i] = 0;
    }
    for (int i : nums) {
      if (m[i] == 0) {
        result = max(result, dfs(m, i));
      }
    }
    return nums.size() ? result : 0;
  }
};
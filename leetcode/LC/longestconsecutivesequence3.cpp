//
// Created by Ahsan Ghani on 2022-09-29.
//
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    map<int, int> m;
    int maxlength = 0;
    int currentlength = 1;

    if (n == 0) {
      return n;
    }

    for (int i = 0; i < n; i++) {
      // insert into map
      m[nums[i]] = 1;
    }

    for (int j = 0; j < n; j++) {
      // if it -1 is in the map
      if (m.find(nums[j] - 1) != m.end()) {
        // it is not the start point
        m[nums[j]] = 0;
      }
    }

    for (int k = 0; k < n; k++) {
      // find starting point
      if (m[nums[k]] == 1) {
        int length = 1;

        // if length is in map, find the rest of the length until it breaks
        while (m.find(nums[k] + length) != m.end()) {
          length++;
        }

        maxlength = max(maxlength, length);
      }
    }

    return maxlength;
  }
};
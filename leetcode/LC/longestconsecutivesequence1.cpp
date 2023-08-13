//
// Created by Ahsan Ghani on 2022-09-29.
//
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    sort(nums.begin(), nums.end());

    int maxlength = 0;
    int currentlength = 1;

    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1] + 1) {
        currentlength++;
      } else if (nums[i] != nums[i - 1]) {
        maxlength = max(maxlength, currentlength);
        currentlength = 1;
      }
    }

    maxlength = max(maxlength, currentlength);
    return maxlength;
  }
};
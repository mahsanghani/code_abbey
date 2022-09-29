//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> results(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        results[i] = results[i] * nums[j];
      }
    }

    return results;
  }
};
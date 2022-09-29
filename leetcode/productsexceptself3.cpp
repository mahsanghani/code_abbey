//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> results(n);
    int leftprod = 1;
    results[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
      results[i] = nums[i + 1] * results[i + 1];
    }

    for (int j = 0; j < n; j++) {
      results[j] = leftprod * results[j];
      leftprod = leftprod * nums[j];
    }

    return results;
  }
};
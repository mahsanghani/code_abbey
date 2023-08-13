//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> m;
    vector<int> results;
    vector<vector<int>> buckets(nums.size() + 1);

    for (auto num : nums) {
      m[num]++;
    }

    for (auto [a, b] : m) {
      buckets[b].push_back(a);
    }

    for (int i = nums.size(); k; i--) {
      for (auto a : buckets[i]) {
        results.push_back(a);
        k--;
      }
    }

    return results;
  }
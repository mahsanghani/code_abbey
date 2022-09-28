//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> m;
    vector<int> results;
    priority_queue<pair<int, int>> pq;

    for (auto num : nums) {
      m[num]++;
    }

    for (auto [a, b] : m) {
      pq.push({b, a});
    }

    while (k) {
      results.push_back(pq.top().second);
      pq.pop();
      k--;
    }

    return results;
  }
};
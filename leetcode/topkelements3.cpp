//
// Created by Ahsan Ghani on 2022-09-28.
//
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    int n = nums.size();

    map<int, int> m;
    vector<int> results;
    vector<vector<int>> buckets(n + 1);

    for (int i = 0; i < n; i++) {
      m[nums[i]]++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      buckets[it->second].push_back(it->first);
    }

    for (int j = n; j >= 0; j--) {
      if (results.size() >= k) {
        break;
      }
      if (!buckets[j].empty()) {
        results.insert(results.end(), buckets[j].begin(), buckets[j].end());
      }
    }

    return results;
  }
};
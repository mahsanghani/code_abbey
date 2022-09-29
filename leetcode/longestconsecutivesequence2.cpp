//
// Created by Ahsan Ghani on 2022-09-29.
//
class Solution {
public:
  int p[100001];
  int r[100001];

  int find(int a) {
    if (p[a] == a) {
      return a;
    }
    return p[a] = find(p[a]);
  }

  void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
      return;
    }

    if (r[a] > r[b]) {
      p[b] = a;
      r[a] += r[b];
    } else {
      p[a] = b;
      r[b] += r[a];
    }
  }

  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    for (int i = 0; i < n; i++) {
      p[i] = i;
      r[i] = 1;
    }

    map<int, int> m;

    for (int j = 0; j < n; j++) {
      // if it is in the map
      if (m.find(nums[j]) != m.end()) {
        continue;
      }

      // if it -1 is in the map
      if (m.find(nums[j] - 1) != m.end()) {
        Union(m[nums[j] - 1], j);
      }

      // if it +1 is in the map
      if (m.find(nums[j] + 1) != m.end()) {
        Union(m[nums[j] + 1], j);
      }

      m[nums[j]] = j;
    }

    int results = 0;
    for (int k = 0; k < n; k++) {
      results = max(results, r[k]);
    }

    return results;
  }
};
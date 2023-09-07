#
# @lc app=leetcode id=2272 lang=python3
#
# [2272] Substring With Largest Variance
#

# @lc code=start
import collections
from collections import defaultdict
class Solution:
    def largestVariance(self, s: str) -> int:
        pos = defaultdict(list)
        for i,j in enumerate(s):
            pos[j].append(i)
        results = 0
        for a in pos.keys():
            for b in pos.keys():
                if a == b:
                    continue
                A, B = len(pos[a]), len(pos[b])
                a_idx = 0
                b_idx = 0
                run_sum = 0
                has_a = False
                has_b = False
                while a_idx < A or b_idx < B:
                    if a_idx < A and (b_idx == B or pos[a][a_idx] < pos[b][b_idx]):
                        run_sum += 1
                        has_a = True
                        a_idx += 1
                    elif b_idx < B:
                        run_sum -= 1
                        has_b = True
                        b_idx += 1
                    if run_sum < 0 and a_idx < A and b_idx < B:
                        run_sum = 0
                        has_a = False
                        has_b = False
                    if has_a and has_b:
                        results = max(results, run_sum)
        return results

# @lc code=end


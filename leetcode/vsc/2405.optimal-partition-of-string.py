#
# @lc app=leetcode id=2405 lang=python3
#
# [2405] Optimal Partition of String
#

# @lc code=start
import math
class Solution:
    def partitionString(self, s: str) -> int:
        cur = set()
        results = 0

        for c in s:
            if c in cur:
                results+=1
                cur = set()
                cur.add(c)
            else:
                cur.add(c)
        return results
# @lc code=end


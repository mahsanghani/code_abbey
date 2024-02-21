#
# @lc app=leetcode id=2405 lang=python3
#
# [2405] Optimal Partition of String
#

# @lc code=start
class Solution:
    def partitionString(self, s: str) -> int:
        unique = set()
        results = []
        
        for c in s:
            if c in unique:
                results.append(unique)
                unique = set()
            unique.add(c)

        results.append(unique)
        return len(results)
# @lc code=end


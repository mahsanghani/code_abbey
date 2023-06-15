#
# @lc app=leetcode id=2405 lang=python3
#
# [2405] Optimal Partition of String
#

# @lc code=start
import math
class Solution:
    def partitionString(self, s: str) -> int:
        i,j = 0,1
        results=0
        while i < len(s):
            if len(s[i:j]) == len(set(s[i:j])):
                results += 1
                i+=1
            else:
                j+=1
        return results
# @lc code=end


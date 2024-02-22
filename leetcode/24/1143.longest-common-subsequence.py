#
# @lc app=leetcode id=1143 lang=python3
#
# [1143] Longest Common Subsequence
#
# @lc code=start
from functools import lru_cache
class Solution:
    def longestCommonSubsequence(self, t1: str, t2: str) -> int:
        @lru_cache(maxsize=None)
        def memo(p1,p2):
            if p1==len(t1) or p2==len(t2):
                return 0
            
            option1 = memo(p1+1,p2)
            option2 = 0
            first = t2.find(t1[p1],p2)
            if first>=0:
                option2 = 1+memo(p1+1,first+1)

            return max(option1,option2) 
        return memo(0,0)
# @lc code=end


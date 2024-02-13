#
# @lc app=leetcode id=3032 lang=python3
#
# [3032] Count Numbers With Unique Digits II
#
# @lc code=start
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(str(i))==len(set(str(i))) for i in range(a,b+1))
        
# @lc code=end


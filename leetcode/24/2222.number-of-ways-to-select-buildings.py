#
# @lc app=leetcode id=2222 lang=python3
#
# [2222] Number of Ways to Select Buildings
#
# @lc code=start
class Solution:
    def numberOfWays(self, s: str) -> int:
        res,one,zero,one_zero,zero_one = 0,0,0,0,0
        for c in s:
            if c=="0":
                zero+=1
                one_zero+=one
                res+=zero_one
            else:
                one+=1
                zero_one+=zero
                res+=one_zero
        return res

# @lc code=end


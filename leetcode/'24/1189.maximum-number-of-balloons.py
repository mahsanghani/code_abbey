#
# @lc app=leetcode id=1189 lang=python3
#
# [1189] Maximum Number of Balloons
#

# @lc code=start
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        res=len(text)
        d=Counter(text)
        b=Counter("balloon")
        for c in b:
            res = min(res, d[c]//b[c])
        return res
# @lc code=end


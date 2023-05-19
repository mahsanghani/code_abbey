#
# @lc app=leetcode id=1189 lang=python3
#
# [1189] Maximum Number of Balloons
#

# @lc code=start
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        res=0
        d=Counter(text)
        while d['b']>0:
            if d['b']>=1 and d['a']>=1 and d['l']>=2 and d['o']>=2 and d['n']>=1:
                res+=1
                d['b']-=1
                d['a']-=1
                d['l']-=2
                d['o']-=2
                d['n']-=1
        return res
# @lc code=end


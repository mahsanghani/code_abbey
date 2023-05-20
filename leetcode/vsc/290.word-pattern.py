#
# @lc app=leetcode id=290 lang=python3
#
# [290] Word Pattern
#

# @lc code=start
class Solution:
    def wordPattern(self, p: str, s: str) -> bool:
        dp=defaultdict(set)
        ds=defaultdict(set)

        if len(list(p))!=len(list(s.split(" "))):
            return False
        
        for i,j in zip(list(p),s.split(" ")):
            dp[i].add(j)

        for i,j in zip(list(p),s.split(" ")):
            ds[j].add(i)

        for k,v in dp.items():
            if len(v)>1:
                return False
        
        for k,v in ds.items():
            if len(v)>1:
                return False
        
        return True
# @lc code=end


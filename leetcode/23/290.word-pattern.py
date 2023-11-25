#
# @lc app=leetcode id=290 lang=python3
#
# [290] Word Pattern
#

# @lc code=start
class Solution:
    def wordPattern(self, p: str, s: str) -> bool:
        dp=defaultdict(list)
        ds=defaultdict(list)

        if len(list(p))!=len(list(s.split(" "))):
            return False
        
        for i,j in zip(list(p),s.split(" ")):
            dp[i].append(j)

        for i,j in zip(list(p),s.split(" ")):
            ds[j].append(i)

        for k,v in dp.items():
            if len(set(v))>1:
                return False
        
        for k,v in ds.items():
            if len(set(v))>1:
                return False
        
        return True
# @lc code=end


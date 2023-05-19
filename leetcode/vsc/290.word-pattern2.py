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

        if len(list(p))!=len(s.split(" ")):
            return False

        for i,j in zip(list(p),s.split(" ")):
            if i in dp and dp[i]!=j:
                return False
            if j in ds and ds[j]!=i:
                return False
            dp[i]=j
            ds[j]=i
        return True
# @lc code=end


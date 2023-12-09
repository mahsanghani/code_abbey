#
# @lc app=leetcode id=1688 lang=python3
#
# [1688] Count of Matches in Tournament
#

# @lc code=start
class Solution:
    def numberOfMatches(self, n: int) -> int:
        results = 0

        while n>1:
            if n%2==0:
                results+=n/2
                n = n/2
            else:
                results+=(n-1)/2+1
                n = (n-1)/2
        
        return int(results)
# @lc code=end


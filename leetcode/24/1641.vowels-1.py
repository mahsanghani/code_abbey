#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        return self.bt(n,1)
    
    def bt(self, n,v):
        if n==0:
            return 1
        results = 0
        for i in range(v,6):
            results+=self.bt(n-1,i)
        return results
# @lc code=end


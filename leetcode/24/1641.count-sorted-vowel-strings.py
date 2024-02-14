#
# @lc app=leetcode id=1641 lang=python3
#
# [1641] Count Sorted Vowel Strings
#

# @lc code=start
class Solution:
    def countVowelStrings(self, n: int) -> int:
        return self.recursion(n,5)
    
    def recursion(self, n,v):
        if n==1:
            return v
        if v==1:
            return 1
        return self.recursion(n-1,v) + \
                self.recursion(n,v-1)
# @lc code=end


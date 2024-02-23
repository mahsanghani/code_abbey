#
# @lc app=leetcode id=2330 lang=python3
#
# [2330] Valid Palindrome IV
#

# @lc code=start
class Solution:
    def makePalindrome(self, s: str) -> bool:
        i,j,op = 0,len(s)-1,2

        while i<j and op>=0:
            if s[i]!=s[j]:
                op-=1
            i+=1
            j-=1
        return op>=0 and j<=i
# @lc code=end


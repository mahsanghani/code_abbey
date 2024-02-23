#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#

# @lc code=start
from collections import Counter
class Solution:
    def validPalindrome(self, s: str) -> bool:
        l,r = 0,len(s)-1

        def check(s,l,r):
            while l<r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True

        while l<r:
            if s[l]!=s[r]:
                return check(s,l+1,r) or check(s,l,r-1)
            l+=1
            r-=1
        return True

# @lc code=end


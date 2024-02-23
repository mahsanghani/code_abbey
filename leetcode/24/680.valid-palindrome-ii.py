#
# @lc app=leetcode id=680 lang=python3
#
# [680] Valid Palindrome II
#

# @lc code=start
from collections import Counter
class Solution:
    def validPalindrome(self, s: str) -> bool:
        counts = Counter(s)
        odd,even = 0,0
        for k,v in counts.items():
            if v%2==0:
                even+=1
            else:
                odd+=1
        return odd<2 if len(s)%2==0 else odd<3
# @lc code=end


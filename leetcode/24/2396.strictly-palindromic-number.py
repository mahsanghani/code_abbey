#
# @lc app=leetcode id=2396 lang=python3
#
# [2396] Strictly Palindromic Number
#

# @lc code=start
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        if len(str(n))<2:
            return False
        if str(n)==str(n)[::-1]:
            return False
# @lc code=end


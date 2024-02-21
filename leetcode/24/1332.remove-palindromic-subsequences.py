#
# @lc app=leetcode id=1332 lang=python3
#
# [1332] Remove Palindromic Subsequences
#

# @lc code=start
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if not s:
            return 0
        elif s==s[::-1]:
            return 1
        else:
            return 2
# @lc code=end


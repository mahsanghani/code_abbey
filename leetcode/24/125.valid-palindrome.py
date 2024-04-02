#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#
# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(c for c in s if c.isalnum())
        return s.lower().strip()==s[::-1].lower().strip()
# @lc code=end


#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        return [''.join(w.lower()) for w in s if w.isalnum()][::-1] == [''.join(w.lower()) for w in s if w.isalnum()]
# @lc code=end


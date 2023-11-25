#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        results = ""
        length = 0

        for i in range(len(s)):
            left = i
            right = i
            while left>=0 and right<len(s) and s[left]==s[right]:
                if (right-left+1) > length:
                    results = s[left:right+1]
                    length = right-left+1
                left -= 1
                right += 1

            left = i
            right = i+1

            while left>=0 and right<len(s) and s[left]==s[right]:
                if (right-left+1) > length:
                    results = s[left:right+1]
                    length = right-left+1
                left -= 1
                right += 1
        
        return results
# @lc code=end


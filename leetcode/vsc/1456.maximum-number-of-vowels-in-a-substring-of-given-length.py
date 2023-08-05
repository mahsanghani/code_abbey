#
# @lc app=leetcode id=1456 lang=python3
#
# [1456] Maximum Number of Vowels in a Substring of Given Length
#

# @lc code=start
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        l,r,total,results = 0,0,0,0
        vowels = {'a','e','i','o','u'}
        for r in range(len(s)):
            total += 1 if s[r] in vowels else 0
            while (r-l+1)>k:
                total -= 1 if s[l] in vowels else 0
                l += 1
            results = max(results, total)
        return results
# @lc code=end


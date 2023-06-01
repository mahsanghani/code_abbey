#
# @lc app=leetcode id=2002 lang=python3
#
# [2002] Maximum Product of the Length of Two Palindromic Subsequences
#

# @lc code=start
class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
        pali = {}

        for mask in range(1,1<<n):
            sub = ""
            for i in range(n):
                if mask & (1<<i):
                    sub += s[i]
            if sub == sub[::-1]:
                pali[mask] = len(sub)

        results = 0
        for m in pali:
            for n in pali:
                if m & n == 0:
                    results = max(results, pali[m] * pali[n])
        
        return results
# @lc code=end


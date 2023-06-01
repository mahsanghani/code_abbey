#
# @lc app=leetcode id=2002 lang=python3
#
# [2002] Maximum Product of the Length of Two Palindromic Subsequences
#

# @lc code=start
class Solution:
    def maxProduct(self, s: str) -> int:
        p = {}
        n = len(s)

        for mask in range(1,1<<n):
            sub = ""
            for i in range(n):
                if mask & (1<<i):
                    sub += s[i]
            if sub == sub[::-1]:
                p[mask] = len(sub)
        
        results = 0
        for m in p:
            for n in p:
                if m & n == 0:
                    results = max(results, p[m]*p[n])
        
        return results
# @lc code=end


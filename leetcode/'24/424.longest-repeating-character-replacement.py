#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = {}
        l,r = 0,1
        results = 0

        for r in range(len(s)):
            counts[s[r]] = 1 + counts.get(s[r],0)
            while (r-l+1) - max(counts.values()) > k:
                counts[s[l]] -= 1
                l += 1
            results = max(results, r-l+1)
        
        return results
# @lc code=end


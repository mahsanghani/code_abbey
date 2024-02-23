#
# @lc app=leetcode id=2268 lang=python3
#
# [2268] Minimum Number of Keypresses
#
# @lc code=start
from collections import Counter
class Solution:
    def minimumKeypresses(self, s: str) -> int:
        sorted_counts = sorted(Counter(s).values(),reverse=True)
        return sum((k//9+1)*v for k,v in enumerate(sorted_counts))
        
# @lc code=end


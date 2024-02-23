#
# @lc app=leetcode id=2268 lang=python3
#
# [2268] Minimum Number of Keypresses
#
# @lc code=start
from collections import Counter
class Solution:
    def minimumKeypresses(self, s: str) -> int:
        counts = Counter(s)
        results,count = 0,0
        for key,value in enumerate(sorted(counts.values(), reverse=True)):
            if key%9==0:
                count+=1
            results+=count*value
        return results
# @lc code=end


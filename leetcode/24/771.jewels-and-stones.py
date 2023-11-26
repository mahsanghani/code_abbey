#
# @lc app=leetcode id=771 lang=python3
#
# [771] Jewels and Stones
#

# @lc code=start
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        results=0
        for s in stones:
            if s in jewels:
                results+=1
        return results
# @lc code=end


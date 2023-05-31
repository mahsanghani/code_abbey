#
# @lc app=leetcode id=1963 lang=python3
#
# [1963] Minimum Number of Swaps to Make the String Balanced
#

# @lc code=start
class Solution:
    def minSwaps(self, s: str) -> int:
        closing = 0
        results = 0
        for c in s:
            if c == "[":
                closing-=1
            else:
                closing+=1
            results = max(closing, results)
        return (results+1)//2
# @lc code=end


#
# @lc app=leetcode id=2149 lang=python3
#
# [2149] Rearrange Array Elements by Sign
#

# @lc code=start
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = [num for num in nums if num>0]
        neg = [num for num in nums if num<0]
        res = [item for pair in zip(pos,neg) for item in pair]

        return res
# @lc code=end


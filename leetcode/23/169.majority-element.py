#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#

# @lc code=start
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d=Counter(nums)

        for k,v in d.items():
            if v > len(nums)/2:
                return k
# @lc code=end


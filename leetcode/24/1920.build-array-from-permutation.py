#
# @lc app=leetcode id=1920 lang=python3
#
# [1920] Build Array from Permutation
#

# @lc code=start
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            ans.append(nums[n])
        return ans
# @lc code=end


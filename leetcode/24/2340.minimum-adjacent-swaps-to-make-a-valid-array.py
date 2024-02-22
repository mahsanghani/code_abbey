#
# @lc app=leetcode id=2340 lang=python3
#
# [2340] Minimum Adjacent Swaps to Make a Valid Array
#

# @lc code=start
class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        mini = min(nums)
        maxi = max(nums)
        idx1 = nums.index(mini)
        idx2 = nums.index(maxi)

        nums = [nums[idx1]] + nums[:idx1] + nums[idx1+1:]

        return idx1 + idx2
# @lc code=end


#
# @lc app=leetcode id=2340 lang=python3
#
# [2340] Minimum Adjacent Swaps to Make a Valid Array
#

# @lc code=start
class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        mini = min(nums)
        idx1 = nums.index(mini)

        nums = [nums[idx1]] + nums[:idx1] + nums[idx1+1:]

        maxi = max(nums)
        idx2 = nums[::-1].index(maxi)

        return idx1 + idx2
# @lc code=end


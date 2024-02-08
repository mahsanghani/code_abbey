#
# @lc app=leetcode id=1877 lang=python3
#
# [1877] Minimize Maximum Pair Sum in Array
#

# @lc code=start
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        sums, pairs = [], []
        nums.sort()
        for i in range(len(nums)//2):
            pairs.append([nums[i],nums[-i-1]])
            print([nums[i],nums[-i-1]])
        for j in range(len(pairs)):
            sums.append(sum(pairs[j]))
        return max(sums)
# @lc code=end


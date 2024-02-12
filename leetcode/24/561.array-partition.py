#
# @lc app=leetcode id=561 lang=python3
#
# [561] Array Partition
#

# @lc code=start
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        i=0
        results=[]
        nums.sort()
        while i<len(nums)-1:
            results.append(min(nums[i], nums[i+1]))
            i+=2
        return sum(results)
# @lc code=end


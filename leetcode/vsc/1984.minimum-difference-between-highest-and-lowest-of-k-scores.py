#
# @lc app=leetcode id=1984 lang=python3
#
# [1984] Minimum Difference Between Highest and Lowest of K Scores
#

# @lc code=start
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        difference = float("inf")
        nums.sort()
        l,r = 0,k-1
        while r<len(nums):
            difference = min(difference, nums[r]-nums[l])
            l+=1
            r+=1
        return difference

# @lc code=end


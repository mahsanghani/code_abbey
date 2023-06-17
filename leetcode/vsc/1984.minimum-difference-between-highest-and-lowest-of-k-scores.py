#
# @lc app=leetcode id=1984 lang=python3
#
# [1984] Minimum Difference Between Highest and Lowest of K Scores
#

# @lc code=start
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        res = float("inf")
        nums.sort()
        l,r = 0,k-1
        while r<len(nums):
            res = min(res, nums[r]-nums[l])
            l+=1
            r+=1
        return res

# @lc code=end


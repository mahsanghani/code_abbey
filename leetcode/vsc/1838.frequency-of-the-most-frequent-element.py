#
# @lc app=leetcode id=1838 lang=python3
#
# [1838] Frequency of the Most Frequent Element
#

# @lc code=start
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        l,r,total,results = 0,0,0,0

        nums.sort()

        while r<len(nums):
            total += nums[r]

            while nums[r]*(r-l+1) > total+k:
                total -= nums[l]
                l += 1
            
            results = max(results, r-l+1)
            r += 1
        
        return results
# @lc code=end


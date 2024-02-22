#
# @lc app=leetcode id=2422 lang=python3
#
# [2422] Merge Operations to Turn Array Into a Palindrome
#

# @lc code=start
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        results = 0
        left, right = 0, len(nums)-1
        while left<right:
            if nums[left]==nums[right]:
                left+=1
                right-=1
            else:
                if nums[left]+nums[left+1] < nums[right]+nums[right-1]:
                    nums[left+1]+=nums[left]
                    left+=1
                else:
                    nums[right-1]+=nums[right]
                    right-=1
                results+=1
        return results
# @lc code=end


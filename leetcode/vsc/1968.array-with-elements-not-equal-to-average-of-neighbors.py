#
# @lc app=leetcode id=1968 lang=python3
#
# [1968] Array With Elements Not Equal to Average of Neighbors
#

# @lc code=start
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        l,r = 0, len(nums)-1
        results = []

        while len(results)!=len(nums):
            results.append(nums[l])
            l+=1

            if l<=r:
                results.append(nums[r])
                r-=1
        
        return results
# @lc code=end


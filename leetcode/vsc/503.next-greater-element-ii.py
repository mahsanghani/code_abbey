#
# @lc app=leetcode id=503 lang=python3
#
# [503] Next Greater Element II
#

# @lc code=start
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        length = len(nums)
        nums = nums + nums
        results = [-1]*length
        count = 0

        for i in range(len(nums)):
            for j in range(i+1,i+length):
                if nums[j]>nums[i]:
                    results[i] = nums[j]
                    break
            count+=1

            if count==1:
                break

        return results
# @lc code=end


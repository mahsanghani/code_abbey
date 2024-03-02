#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def heapify(n,i):
            largest = i
            left = 2*i+1
            right = 2*i+2
            if left<n and nums[left]>nums[largest]:
                largest = left
            if right<n and nums[right]>nums[largest]:
                largest = right
            if largest!=i:
                nums[i],nums[largest] = nums[largest], nums[i]
                heapify(n,largest)
# @lc code=end


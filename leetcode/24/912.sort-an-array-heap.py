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

        def heap_sort():
            n = len(nums)
            for i in range(n//2-1,-1,-1):
                heapify(n,i)
            for j in range(n-1,-1,-1):
                nums[0],nums[j] = nums[j], nums[0]
                heapify(j,0)

        heap_sort()
        return nums
# @lc code=end


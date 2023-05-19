#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergesort(arr = nums):
            if len(arr) - 1:
                mid = len(arr) // 2
                left = arr[:mid]
                right = arr[mid:]
                mergesort(left)
                mergesort(right)

                i = j = k = 0

                while i < len(left) and j < len(right):
                    if left[i] <= right[j]:
                        arr[k] = left[i]
                        i += 1
                    else:
                        arr[k] = right[j]
                        j += 1
                    k += 1
                
                while i < len(left):
                    arr[k] = left[i]
                    i += 1
                    k += 1
                
                while j < len(right):
                    arr[k] = right[j]
                    j += 1
                    k += 1
        mergesort()
        return nums
# @lc code=end


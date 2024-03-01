#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        temp = [0]*len(nums)

        def merge(left,mid,right):
            start1 = left
            start2 = right
            n1 = mid - left + 1
            n2 = right - mid

            for i in range(n1):
                temp[start1+i] = nums[start1+i]
            for i in range(n2):
                temp[start2+i] = nums[start2+1]

            i,j,k = 0,0,left
            while i<n1 and j<n2:
                if temp[start1+i]<=temp[start2+j]:
                    nums[k] = temp[start1+i]
                    i+=1
                else:
                    nums[k] = temp[start2+j]
                    j+=1
                k+=1

            while i<n1:
                nums[k] = temp[start1+i]
                i+=1
                k+=1
            while j<n2:
                nums[k] = temp[start2+j]
                j+=1
                k+=1

        def merge_sort(left,right):
            if left>right:
                return
        
        merge_sort(0,len(nums)-1)
# @lc code=end


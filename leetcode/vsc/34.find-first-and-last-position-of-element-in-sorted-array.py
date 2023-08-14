#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]
        
        def binarysearch(nums,target,find):
            i,j,k = -1,0,len(nums)-1

            while j<=k:
                # mid = (j+k)//2
                mid = j + (k-j)//2

                if nums[mid] == target:
                    i = mid
                    if find:
                        k = mid - 1
                    else:
                        j = mid + 1
                    
                elif nums[mid] < target:
                    j = mid + 1
                else:
                    k = mid - 1

            return i
        
        left = binarysearch(nums,target,True)
        if left==-1:
            return [-1,-1]
        
        right = binarysearch(nums,target,False)
        return [left,right]
# @lc code=end


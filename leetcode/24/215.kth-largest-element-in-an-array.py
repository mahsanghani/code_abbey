#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
# @lc code=start
class Solution:
    def partition(self,nums,l,r):
        ptr,pvt = l,nums[r]

        for i in range(l,r):
            if nums[i]<=pvt:
                nums[ptr],nums[i] = nums[i],nums[ptr]
                ptr+=1
        
        nums[ptr],nums[r] = nums[r],nums[ptr]

        return ptr

    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums)-k
        l,r = 0,len(nums)-1
        
        while l<r:
            pvt = self.partition(nums,l,r)
            
            if pvt<k:
                l=pvt+1
            elif pvt>k:
                r=pvt-1
            else:
                break
    
        return nums[k]
# @lc code=end


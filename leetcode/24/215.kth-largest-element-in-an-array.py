#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums)-k
        # l,r = 0,len(nums)-1

        def quickselect(l,r):
            ptr,pvt = l,nums[r]

            for i in range(l,r):
                if nums[i]<=pvt:
                    nums[ptr],nums[i] = nums[i],nums[ptr]
                    ptr+=1
            nums[ptr],nums[r] = nums[r],nums[ptr]

            if k<ptr:
                return quickselect(l,ptr-1)
            if k>ptr:
                return quickselect(ptr+1,r)
            else:
                return nums[ptr]
            
        return quickselect(0,len(nums)-1)
# @lc code=end


#
# @lc app=leetcode id=1822 lang=python3
#
# [1822] Sign of the Product of an Array
#

# @lc code=start
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        numset = set(nums)
        if 0 in numset:
            return 0
        
        d={-1:0, 1:0}

        for num in nums:
            if num<0:
                d[-1]+=1
            elif num>0:
                d[1]+=1
            else:
                return 0
        
        if d[-1]%2==0:
            return 1
        else:
            return -1
        
# @lc code=end


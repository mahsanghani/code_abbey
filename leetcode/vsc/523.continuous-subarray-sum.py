#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#

# @lc code=start
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d={0:-1}
        t=0

        for i,j in enumerate(nums):
            t+=j
            r=t%k
            if r not in d:
                d[r]=i
            elif i-d[r]>1:
                return True
            
        return False
        # for k,v in d.items():
        #     if len(v)>1:
        #         return True
        #     else:
        #         return False
# @lc code=end


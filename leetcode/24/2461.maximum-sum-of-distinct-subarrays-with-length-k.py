#
# @lc app=leetcode id=2461 lang=python3
#
# [2461] Maximum Sum of Distinct Subarrays With Length K
#
# @lc code=start
from collections import Counter
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ctr = Counter()
        l,s,r = 0,0,0

        for i in range(n):
            s+=nums[i]
            if ctr[nums[i]]==0:
                l+=1
            ctr[nums[i]]+=1
            if i>=k:
                s-=nums[i-k]
                ctr[nums[i-k]]-=1
                if ctr[nums[i-k]]==0:
                    l-=1
            if i>=k-1:
                if l==k:
                    r=max(r,s)
        return r

# @lc code=end


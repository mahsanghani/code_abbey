#
# @lc app=leetcode id=179 lang=python3
#
# [179] Largest Number
#

# @lc code=start
import collections
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        for i,j in enumerate(nums):
            nums[i] = str(j)

        def compare(n,m):
            if n+m>m+n:
                return -1
            else:
                return 1
        
        nums = sorted(nums,key=functools.cmp_to_key(compare))
        return str(int("".join(nums)))
# @lc code=end


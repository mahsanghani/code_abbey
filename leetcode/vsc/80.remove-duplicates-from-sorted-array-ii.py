#
# @lc app=leetcode id=80 lang=python3
#
# [80] Remove Duplicates from Sorted Array II
#

# @lc code=start
from collections import Counter
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i,l = 0,len(nums)
        d = Counter(nums)

        while i<l:
            if d[nums[i]]>2:
                nums.pop(i)
                nums.append('_')
                d[nums[i]]-=1
                l-=1
            else:
                i+=1
        return l

# @lc code=end


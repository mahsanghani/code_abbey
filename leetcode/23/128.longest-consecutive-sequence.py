#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        l,m=0,0
        numset=set(nums)

        for num in nums:
            if num-1 not in numset:
                l=0
                while num+l in numset:
                    l+=1
                if l>m:
                    m=l
        return m

# @lc code=end


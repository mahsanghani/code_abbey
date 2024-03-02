#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#
# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxlength = 0
        unique = set(nums)

        for num in nums:
            if num-1 not in unique:
                length = 0
                while num+length in unique:
                    length+=1
                if length>maxlength:
                    maxlength=length
        
        return maxlength
# @lc code=end


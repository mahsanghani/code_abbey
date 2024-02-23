#
# @lc app=leetcode id=2323 lang=python3
#
# [2323] Find Minimum Time to Finish All Jobs II
#
# @lc code=start
from math import ceil
class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        days = 0
        jobs.sort()
        workers.sort()

        for j,w in zip(jobs,workers):
            days = max(days, ceil(j/w))
        
        return days

# @lc code=end


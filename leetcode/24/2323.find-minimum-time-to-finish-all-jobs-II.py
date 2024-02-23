#
# @lc app=leetcode id=2323 lang=python3
#
# [2323] Find Minimum Time to Finish All Jobs II
#
# @lc code=start
class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        days = 0
        jobs.sort()
        workers.sort()

        for i in range(len(jobs)):
            days = max(days, jobs[i]//workers[i])
        
        return days

# @lc code=end


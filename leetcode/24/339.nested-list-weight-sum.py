#
# @lc app=leetcode id=2798 lang=python3
#
# [2798] Number of Employees Who Met the Target
#

# @lc code=start
class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        hours = sorted(hours)

        for i,j in enumerate(hours):
            if j>=target:
                return len(hours)-i
            
        return 0
# @lc code=end


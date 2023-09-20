#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#

# @lc code=start
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack,results = [], [0]*len(temperatures)

        for i,j in enumerate(temperatures):
            while stack and j>stack[-1][0]:
                temp,idx = stack.pop()
                results[idx] = i-idx
            stack.append([j,i])
        return results
# @lc code=end


#
# @lc app=leetcode id=1272 lang=python3
#
# [1272] Remove Interval
#
# @lc code=start
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        results = []
        intervals.sort()
        for interval in intervals:
            if interval[0]>=toBeRemoved[1] or interval[1]<=toBeRemoved[0]:
                results.append([interval[0],interval[1]])
            else:
                if interval[0]<toBeRemoved[0]:
                    results.append([interval[0],toBeRemoved[0]])
                if interval[1]>toBeRemoved[1]:
                    results.append([toBeRemoved[1],interval[1]])
        return results
# @lc code=end


#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#
# @lc code=start
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        results = []
        intervals.append(newInterval)
        intervals.sort()

        for interval in intervals:
            if not results or results[-1][1] < interval[0]:
                results.append(interval)
            else:
                results[-1][1] = max(results[-1][1], interval[1])

        return results
# @lc code=end


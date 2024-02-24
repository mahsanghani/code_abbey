#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        results = []
        intervals.sort()
        for interval in intervals:
            if not results or results[-1][1]<interval[0]:
                results.append(interval)
            else:
                results[-1][1] = max(results[-1][1],interval[1])
        return results
# @lc code=end


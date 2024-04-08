#
# @lc app=leetcode id=630 lang=python3
#
# [630] Course Schedule III
#
# @lc code=start
import heapq
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x:x[1])
        results = []
        current = 0

        for duration, lastday in courses:
            heapq.heappush(results,-duration)
            current += duration
            if current > lastday:
                current += heapq.heappop(results)
        return len(results)
# @lc code=end


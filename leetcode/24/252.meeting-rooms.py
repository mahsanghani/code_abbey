#
# @lc app=leetcode id=252 lang=python3
#
# [252] Meeting Rooms
#
# @lc code=start
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()

        for i in range(len(intervals)-1):
            i1 = intervals[i]
            i2 = intervals[i+1]
            if i2[0]<i1[1]:
                return False
            
        return True
# @lc code=end


#
# @lc app=leetcode id=253 lang=python3
#
# [253] Meeting Rooms II
#
# @lc code=start
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        s,e,results,rooms = 0,0,0,0

        start = sorted([i[0] for i in intervals])
        end = sorted([i[1] for i in intervals])
        
        while s<len(intervals):
            if start[s]<end[e]:
                s+=1
                rooms+=1
            else:
                e+=1
                rooms-=1
            results = max(results,rooms)

        return results

# @lc code=end


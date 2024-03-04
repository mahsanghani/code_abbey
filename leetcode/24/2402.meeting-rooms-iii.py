#
# @lc app=leetcode id=2402 lang=python3
#
# [2402] Meeting Rooms III
#
# @lc code=start
from heapq import heappush, heappop
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        used = []
        unused = [i for i in range(n)]
        counts = [0]*n
        meetings.sort()

        for s,e in meetings:
            while used and s>=used[0][0]:
                _, room = heappop(used)
                heappush(unused, room)

            if not unused:
                time, room = heappop(used)
                e = time + (e - s)
                heappush(unused, room)

            room = heappop(unused)
            heappush(used, (e,room))
            counts[room] += 1

        return counts.index(max(counts))
# @lc code=end


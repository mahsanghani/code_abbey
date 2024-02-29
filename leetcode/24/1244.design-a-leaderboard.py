#
# @lc app=leetcode id=1244 lang=python3
#
# [1244] Design A Leaderboard
#
# @lc code=start
from heapq import heappush, heappop
from collections import defaultdict
from sortedcontainers import SortedDict
class Leaderboard:
    def __init__(self):
        self.scores = {}

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = 0
        self.scores[playerId] += score

    def top(self, K: int) -> int:
        heap = []
        for x in self.scores.values():
            heappush(heap,x)
            if len(heap)>K:
                heappop(heap)
        results = 0
        while heap:
            results+=heappop(heap)
        return results

    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0

# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
# @lc code=end


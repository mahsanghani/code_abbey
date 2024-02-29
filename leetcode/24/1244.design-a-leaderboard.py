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
        self.sortedScores = SortedDict()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = score
            self.sortedScores[-score] = self.sortedScores.get(-score,0)+1
        else:
            pre = self.scores[playerId]
            val = self.sortedScores.get(-pre)
            if val==1:
                del self.sortedScores[-pre]
            else:
                self.sortedScores[-pre]=val-1
            newscore = pre+score
            self.scores[playerId] = newscore
            self.sortedScores[-newscore] = self.sortedScores.get(-newscore,0)+1
        

    def top(self, K: int) -> int:
        count, total = 0,0
        for k,v in self.sortedScores.items():
            times = self.sortedScores.get(k)
            for i in range(times):
                total += -k
                count += 1
                if count==K:
                    break
            if count==K:
                break
        return total

    def reset(self, playerId: int) -> None:
        pre = self.scores[playerId]
        if self.sortedScores[-pre]==1:
            del self.sortedScores[-pre]
        else:
            self.sortedScores[-pre]-=1
        del self.scores[playerId]

# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
# @lc code=end


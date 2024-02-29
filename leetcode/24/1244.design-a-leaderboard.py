#
# @lc app=leetcode id=1244 lang=python3
#
# [1244] Design A Leaderboard
#
# @lc code=start
from collections import defaultdict
class Leaderboard:
    def __init__(self):
        self.scores = defaultdict()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = 0
        self.scores[playerId] += score

    def top(self, K: int) -> int:
        values = [v for _,v in sorted(self.scores.items(), key=lambda item: item[1])]
        values.sort(reverse=True)
        i,t = 0,0
        while i<K:
            t+=values[i]
            i+=1
        return t

    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
# @lc code=end


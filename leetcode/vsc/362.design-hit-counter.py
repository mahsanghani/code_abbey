#
# @lc app=leetcode id=362 lang=python3
#
# [362] Design Browser History
#

# @lc code=start
class HitCounter:

    def __init__(self):
        self.hits = {}

    def hit(self, timestamp: int) -> None:
        if timestamp not in self.hits:
            self.hits[timestamp] = 0
        # else:
        self.hits[timestamp] += 1

    def getHits(self, timestamp: int) -> int:
        begin = timestamp - 300
        ts_hits = 0
        for i in range(begin+1,timestamp+1):
            if i in self.hits:
                ts_hits += self.hits[i]
        return ts_hits


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
# @lc code=end


#
# @lc app=leetcode id=1396 lang=python3
#
# [1396] Design Underground System
#

# @lc code=start
class UndergroundSystem:

    def __init__(self):
        self.check = {} # (start, time)
        self.total = {} # (start, end)

    def checkIn(self, id: int, start: str, time: int) -> None:
        self.check[id] = (start, time)

    def checkOut(self, id: int, end: str, time: int) -> None:
        

    def getAverageTime(self, start: str, end: str) -> float:
        total, count = self.total([start, end])
        return total / count


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
# @lc code=end


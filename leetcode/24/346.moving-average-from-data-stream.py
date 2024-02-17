#
# @lc app=leetcode id=346 lang=python3
#
# [346] Moving Average from Data Stream
#
# @lc code=start
class MovingAverage:

    def __init__(self, size: int):
        self.size = size
        self.values = []

    def next(self, val: int) -> float:
        self.values.append(val)
        return sum(self.values)/len(self.values) if len(self.values)<self.size else sum(self.values[-self.size:])/self.size


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
# @lc code=end


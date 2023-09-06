#
# @lc app=leetcode id=346 lang=python3
#
# [346] Moving Average from Data Stream
#

# @lc code=start
import collections
from collections import deque
class MovingAverage:

    def __init__(self, size: int):
        self.size = size
        self.queue = deque()
        self.win_sum = 0
        self.count = 0

    def next(self, val: int) -> float:
        self.count += 1
        self.queue.append(val)
        tail = self.queue.popleft() if self.count > self.size else 0
        self.win_sum = self.win_sum - tail + val
        return self.win_sum/min(self.size,self.count)

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
# @lc code=end


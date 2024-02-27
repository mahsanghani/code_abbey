#
# @lc app=leetcode id=933 lang=python3
#
# [933] Number of Recent Calls
#
# @lc code=start
from collections import deque
class RecentCounter:
    def __init__(self):
        self.win = deque()

    def ping(self, t: int) -> int:
        self.win.append(t)
        while self.win[0]<t-3000:
            self.win.popleft()
        return len(self.win)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
# @lc code=end


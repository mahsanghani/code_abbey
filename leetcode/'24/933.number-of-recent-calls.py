#
# @lc app=leetcode id=933 lang=python3
#
# [933] Number of Recent Calls
#

# @lc code=start
import collections
from collections import deque
class RecentCounter:

    def __init__(self):
        self.win_num = deque()

    def ping(self, t: int) -> int:
        self.win_num.append(t)

        while self.win_num[0] < t - 3000:
            self.win_num.popleft()

        return len(self.win_num)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
# @lc code=end


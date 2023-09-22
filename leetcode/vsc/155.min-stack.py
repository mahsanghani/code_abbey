#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start
class MinStack:

    def __init__(self):
        self.stack = []
        self.minst = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        val = min(val, self.minst[-1] if self.minst else val)
        self.minst.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minst.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minst[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end


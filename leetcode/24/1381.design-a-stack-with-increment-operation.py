#
# @lc app=leetcode id=1381 lang=python3
#
# [1381] Design a Stack With Increment Operation
#
# @lc code=start
class CustomStack:
    def __init__(self, maxSize: int):
        self.size = maxSize
        self.stack = []

    def push(self, x: int) -> None:
        if len(self.stack) < self.size:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        temp = self.stack[-1]
        self.stack = self.stack[:-1]
        return temp

    def increment(self, k: int, val: int) -> None:
        if k < len(self.stack):
            for i in range(k):
                self.stack[i] += val
        else:
            self.stack = [each+val for each in self.stack]


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
# @lc code=end


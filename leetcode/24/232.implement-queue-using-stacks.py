#
# @lc app=leetcode id=232 lang=python3
#
# [232] Implement Queue using Stacks
#
# @lc code=start
class MyQueue:
    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        temp = self.stack[0]
        del self.stack[0]
        return temp

    def peek(self) -> int:
        return self.stack[0]

    def empty(self) -> bool:
        return len(self.stack)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end


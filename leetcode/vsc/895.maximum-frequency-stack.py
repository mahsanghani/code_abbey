#
# @lc app=leetcode id=895 lang=python3
#
# [895] Maximum Frequency Stack
#

# @lc code=start
class FreqStack:

    def __init__(self):
        self.count = {}
        self.maxcount = 0
        self.stacks = {}

    def push(self, val: int) -> None:
        valcount = self.count.get(val, 0)+1
        self.count[val] = valcount
        if valcount > self.maxcount:
            self.maxcount = valcount
            self.stacks[valcount] = []
        self.stacks[valcount].append(val)

    def pop(self) -> int:
        results = self.stacks[self.maxcount].pop()
        self.count[results] -= 1
        if not self.stacks[self.maxcount]:
            self.maxcount -= 1
        return results


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
# @lc code=end


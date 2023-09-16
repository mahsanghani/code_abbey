#
# @lc app=leetcode id=682 lang=python3
#
# [682] Baseball Game
#

# @lc code=start
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = []
        ops = ['C','D','+']

        for op in operations:
            if stack and op=='C':
                stack.pop()
            elif stack and op=='D':
                new = 2*stack[-1]
                stack.append(new)
            elif len(stack) >= 2 and op=='+':
                new = stack[-1] + stack[-2]
                stack.append(new)
            else:
                stack.append(int(op))
        return sum(stack)
# @lc code=end


#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for c in tokens:
            if c == '-':
                a = stack.pop()
                b = stack.pop()
                stack.append(b-a)
            elif c == '+':
                stack.append(stack.pop() + stack.pop())
            elif c == '/':
                a = stack.pop()
                b = stack.pop()
                stack.append(int(b/a))
            elif c == '*':
                stack.append(stack.pop() * stack.pop())
            else:
                stack.append(int(c))

        return stack[0]
# @lc code=end


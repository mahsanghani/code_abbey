#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t=='+':
                stack.append(stack.pop()+stack.pop())
            elif t=='*':
                stack.append(stack.pop()*stack.pop())
            elif t=='-':
                a,b = stack.pop(),stack.pop()
                stack.append(b-a)
            elif t=='/':
                a,b = stack.pop(),stack.pop()
                stack.append(int(b/a))
            else:
                stack.append(int(t))

        return stack[0]
# @lc code=end


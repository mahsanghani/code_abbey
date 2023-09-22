#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token=='+':
                stack.append(stack.pop()+stack.pop())
            elif token=='-':
                a,b = stack.pop(),stack.pop()
                stack.append(b-a)
            elif token=='*':
                stack.append(stack.pop()*stack.pop())
            elif token=='/':
                a,b = stack.pop(),stack.pop()
                stack.append(int(b/a))
            else:
                stack.append(int(token))

        return stack[0]
# @lc code=end


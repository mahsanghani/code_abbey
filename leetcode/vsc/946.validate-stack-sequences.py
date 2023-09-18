#
# @lc app=leetcode id=946 lang=python3
#
# [946] Validate Stack Sequences
#

# @lc code=start
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i = 0
        stack = []
        for n in pushed:
            stack.append(n)
            while stack and i < len(popped) and popped[i] == stack[-1]:
                stack.pop()
                i += 1
        return not stack

# @lc code=end


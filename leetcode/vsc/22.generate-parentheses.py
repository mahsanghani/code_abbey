#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
import collections
from collections import deque
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        results = []

        def backtracking(open,close):
            if open==close==n:
                results.append(''.join(stack))
                return
            
            if open<n:
                stack.append('(')
                backtracking(open+1,close)
                stack.pop()

            if open>close:
                stack.append(')')
                backtracking(open,close+1)
                stack.pop()

        backtracking(0,0)
        return results
# @lc code=end


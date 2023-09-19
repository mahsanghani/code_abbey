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

        def bt(o,c):
            if o==c==n:
                results.append(''.join(stack))
                return
            
            if o<n:
                stack.append('(')
                bt(o+1,c)
                stack.pop()

            if c<o:
                stack.append(')')
                bt(o,c+1)
                stack.pop()

        bt(0,0)
        return results
# @lc code=end


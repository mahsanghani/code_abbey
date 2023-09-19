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
        results = []
        
        def bt(curr,left,right):
            if len(curr) == 2*n:
                results.append("".join(curr))
                return
            if left < n:
                curr.append('(')
                bt(curr,left+1,right)
                curr.pop()
            if right < left:
                curr.append(')')
                bt(curr,left,right+1)
                curr.pop()
        
        bt([],0,0)
        return results
# @lc code=end


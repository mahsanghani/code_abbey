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
        queue = collections.deque([''])

        def valid(p):
            left = 0
            for b in p:
                if b == '(':
                    left += 1
                else:
                    left -= 1

                if left < 0:
                    return False
                
            return left == 0
        
        while queue:
            curr = queue.popleft()
            if len(curr) == 2*n:
                if valid(curr):
                    results.append(curr)
                continue
            queue.append(curr+')')
            queue.append(curr+'(')
        
        return results
# @lc code=end


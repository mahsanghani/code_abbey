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
        if n==0:
            return ['']
        
        results = []

        for count in range(n):
            for left in self.generateParenthesis(count):
                for right in self.generateParenthesis(n-1-count):
                    results.append('(' + left + ')' + right)

        return results
# @lc code=end


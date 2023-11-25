#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        d = {'}':'{', ']':'[', ')':'('}

        for c in s:
            if c in d:
                if stack and stack[-1]==d[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        
        return True if not stack else False
# @lc code=end


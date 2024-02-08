#
# @lc app=leetcode id=1614 lang=python3
#
# [1614] Maximum Nesting Depth of the Parentheses
#

# @lc code=start
class Solution:
    def maxDepth(self, s: str) -> int:
        depth, stack = 0, []
        for i,j in enumerate(s):
            if j=='(':
                stack.append(j)
                if len(stack)>depth:
                    depth=len(stack)
            if j==')':
                stack.pop()
        return depth
# @lc code=end


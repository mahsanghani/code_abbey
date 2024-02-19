#
# @lc app=leetcode id=1910 lang=python3
#
# [1910] Remove All Occurrences of a Substring
#

# @lc code=start
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        for c in s:
            stack.append(c)
            if ''.join(stack[-len(part):]) == part:
                for _ in range(len(part)):
                    stack.pop()
        return ''.join(stack)
# @lc code=end


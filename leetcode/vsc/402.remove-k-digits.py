#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []

        for c in num:
            while k and stack and c<stack[-1]:
                k-=1
                stack.pop()

            stack.append(c)

        stack = stack[:-k] if k else stack
        
        return ''.join(stack).lstrip('0') or '0'
# @lc code=end


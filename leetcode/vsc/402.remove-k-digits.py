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
            while stack and k>0 and c<stack[-1]:
                k-=1
                stack.pop()

            stack.append(c)

        stack = stack[:len(stack)-k]

        return str(int(''.join(stack))) if stack else str(0)
# @lc code=end


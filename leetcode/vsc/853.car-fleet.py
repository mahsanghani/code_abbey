#
# @lc app=leetcode id=853 lang=python3
#
# [853] Car Fleet
#

# @lc code=start
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        pairs = [[p,s] for p,s in zip(position,speed)]
        for p,s in sorted(pairs)[::-1]:
            stack.append((target-p)/s)
            while len(stack)>1 and stack[-1]<=stack[-2]:
                stack.pop()
        return len(stack)
# @lc code=end


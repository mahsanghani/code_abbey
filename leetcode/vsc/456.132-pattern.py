#
# @lc app=leetcode id=456 lang=python3
#
# [456] 132 Pattern
#

# @lc code=start
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stack = [] # pair
        current = nums[0]

        for n in nums[1:]:
            while stack and stack[-1][0]<=n:
                stack.pop()
            if stack and stack[-1][1]<n:
                return True
            
            stack.append([n,current])
            current = min(n,current)
        
        return False
# @lc code=end


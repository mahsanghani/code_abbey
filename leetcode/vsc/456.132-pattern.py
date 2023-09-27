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

        for num in nums[1:]:
            while stack and stack[-1][0]<=num:
                stack.pop()
            if stack and stack[-1][1]<num:
                return True
            
            stack.append([num,current])
            current = min(current, num)

        return False
# @lc code=end


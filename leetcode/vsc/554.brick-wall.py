#
# @lc app=leetcode id=554 lang=python3
#
# [554] Brick Wall
#

# @lc code=start
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        gap = {0:0}
        for row in wall:
            total = 0
            for brick in row[:-1]:
                total += brick
                gap[total] = 1+gap.get(total,0)
        
        return len(wall) - max(gap.values())
# @lc code=end
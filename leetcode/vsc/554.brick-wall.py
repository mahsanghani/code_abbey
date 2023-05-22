#
# @lc app=leetcode id=554 lang=python3
#
# [554] Brick Wall
#

# @lc code=start
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        gap={0:0}

        for r in wall:
            t=0
            for b in r[:-1]:
                t+=b
                gap[t]=1+gap.get(t,0)

        return len(wall) - max(gap.values())
        
# @lc code=end


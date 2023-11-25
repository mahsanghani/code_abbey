#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r = 0,len(height)-1
        area=0
        while l<r:
            area=max(area,(r-l)*min(height[l],height[r]))
            if height[l]>height[r]:
                r-=1
            else:
                l+=1
        return area

# @lc code=end


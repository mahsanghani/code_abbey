#
# @lc app=leetcode id=1762 lang=python3
#
# [1762] Buildings With an Ocean View
#

# @lc code=start
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        l,r = len(heights)-2,len(heights)-1
        max_height = heights[r]
        results = [r]
        while l>-1:
            if heights[l]>max_height:
                # print(heights[l])
                results.append(l)
                max_height = heights[l]
            l-=1
            r-=1
        return results[::-1]
# @lc code=end


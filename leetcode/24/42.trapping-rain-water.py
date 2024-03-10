#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#
# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height: 
            return 0
        
        l=0
        pani=0
        r=len(height)-1
        maxLeft = height[l]
        maxRight = height[r]
        
        while l<r:
            if maxLeft < maxRight:
                l+=1
                maxLeft = max(maxLeft, height[l])
                pani += maxLeft - height[l]
            else:
                r-=1
                maxRight = max(maxRight, height[r])
                pani += maxRight - height[r]
                
        return pani
# @lc code=end


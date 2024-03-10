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

        l,p,r = 0,0,len(height)-1
        left,right = height[l],height[r]

        while l<r:
            if left<right:
                l+=1
                left = max(left,height[l])
                p += left - height[l]
            else:
                r-=1
                right = max(right,height[r])
                p += right - height[r]

        return p
# @lc code=end


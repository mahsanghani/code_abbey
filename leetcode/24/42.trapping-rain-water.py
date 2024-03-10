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

        l = 0
        r = len(height)-1
        pani = 0
        left = height[l]
        right = height[r]

        while l<r:
            if left<right:
                l+=1
                left = max(left,height[l])
                pani += left - height[l]
            else:
                r-=1
                right = max(right,height[r])
                pani += right - height[r]

        return pani
# @lc code=end


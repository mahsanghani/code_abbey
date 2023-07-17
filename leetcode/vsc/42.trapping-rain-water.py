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
        
        l,r = 0, len(height)-1
        results = 0
        leftmax, rightmax = height[l], height[r]

        while l<r:
            if leftmax<rightmax:
                l+=1
                leftmax = max(leftmax, height[l])
                results += leftmax-height[l]
            else:
                r-=1
                rightmax = max(rightmax, height[r])
                results += rightmax-height[r]

        return results
# @lc code=end


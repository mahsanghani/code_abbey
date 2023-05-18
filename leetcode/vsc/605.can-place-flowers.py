#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        e=0 if flowerbed[0] else 1
        for f in flowerbed:
            if f:
                n-=int((e-1)/2)
                e=0
            else:
                e+=1
        
        n-=(e)//2
        return n<=0
        
# @lc code=end

#
# @lc app=leetcode id=2782 lang=python3
#
# [2782] Number of Unique Categories
#

# @lc code=start
# Definition for a category handler.
class CategoryHandler:
    def haveSameCategory(self, a: int, b: int) -> bool:
        return a==b

class Solution:
    def numberOfCategories(self, n: int, categoryHandler: Optional['CategoryHandler']) -> int:
        unique = []

        for i in range(n):
            for j in unique:
                if categoryHandler.haveSameCategory(i,j):
                    break
            else:
                unique.append(i)
        
        return len(unique)
# @lc code=end


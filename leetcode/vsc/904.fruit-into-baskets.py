#
# @lc app=leetcode id=904 lang=python3
#
# [904] Fruit Into Baskets
#

# @lc code=start
from collections import Counter
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        fruits = Counter(fruits)
        fruits = sorted((v,k) for k,v in fruits.items())
        return fruits[-1][0] + fruits[-2][0]
# @lc code=end


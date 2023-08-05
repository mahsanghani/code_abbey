#
# @lc app=leetcode id=904 lang=python3
#
# [904] Fruit Into Baskets
#

# @lc code=start
from collections import defaultdict
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        l,r,total,results = 0,0,0,0
        count = defaultdict(int)

        for r in range(len(fruits)):
            count[fruits[r]] += 1
            
            if len(count) > 2:
                count[fruits[l]] -= 1
                if count[fruits[l]] == 0:
                    del count[fruits[l]]
                l+=1
        return r-l+1

# @lc code=end


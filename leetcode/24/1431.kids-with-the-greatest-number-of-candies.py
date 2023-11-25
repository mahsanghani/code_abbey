#
# @lc app=leetcode id=1431 lang=python3
#
# [1431] Kids With the Greatest Number of Candies
#

# @lc code=start
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        m = max(candies)
        results = []
        for kid in candies:
            if kid+extraCandies>=m:
                results.append(True)
            else:
                results.append(False)
        return results
        
# @lc code=end


#
# @lc app=leetcode id=1475 lang=python3
#
# [1475] Final Prices With a Special Discount in a Shop
#

# @lc code=start
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack = []
        results = []
        for i in range(len(prices)):
            while stack and prices[stack[-1]] >= prices[i]:
                index = stack.pop()
                prices[index] -= prices[i]
            stack.append(i)
        return prices

# @lc code=end


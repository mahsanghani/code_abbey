#
# @lc app=leetcode id=2979 lang=python3
#
# [2979] Most Expensive Item That Can Not Be Bought
#

# @lc code=start
class Solution:
    def mostExpensiveItem(self, primeOne: int, primeTwo: int) -> int:
        return primeOne * primeTwo - primeOne - primeTwo
# @lc code=end


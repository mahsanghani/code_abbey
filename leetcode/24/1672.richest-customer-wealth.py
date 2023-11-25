#
# @lc app=leetcode id=1672 lang=python3
#
# [1672] Richest Customer Wealth
#

# @lc code=start
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        balances = []
        for acc in accounts:
            balances.append(sum(acc))
        return max(balances)
# @lc code=end


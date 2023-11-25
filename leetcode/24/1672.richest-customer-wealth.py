#
# @lc app=leetcode id=1672 lang=python3
#
# [1672] Richest Customer Wealth
#

# @lc code=start
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        balance = []
        for account in accounts:
            balance.append(sum(account))
        return max(balance)
# @lc code=end


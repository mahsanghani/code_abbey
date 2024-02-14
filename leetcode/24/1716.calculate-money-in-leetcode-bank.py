#
# @lc app=leetcode id=1716 lang=python3
#
# [1716] Calculate Money in Leetcode Bank
#

# @lc code=start
class Solution:
    def totalMoney(self, n: int) -> int:
        results = 0
        weeks = n//7
        days = n%7
        for i in range(1,(n//7)+1):
            for j in range(i,i+7):
                results+=j
        results+=sum(range(weeks+1,weeks+days+1))
        return results
# @lc code=end


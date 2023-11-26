#
# @lc app=leetcode id=2160 lang=python3
#
# [2160] Minimum Sum of Four Digit Number After Splitting Digits
#

# @lc code=start
class Solution:
    def minimumSum(self, num: int) -> int:
        results = []
        digits = sorted(str(num))
        for i in range(len(digits)//2):
            results.append(int(digits[i]+digits[-i-1]))
        return sum(results)
# @lc code=end


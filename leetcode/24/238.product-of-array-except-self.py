#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results = []
        product = 1
        for num in nums:
            if num>0:
                product *= num
        for num in nums:
            if num>0:
                results.append(int(product/num))
            else:
                results.append(product)
        return results
# @lc code=end


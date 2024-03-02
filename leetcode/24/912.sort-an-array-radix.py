#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# @lc code=start
class Solution:
    def radix_sort(self, nums: List[int]) -> List[int]:
        max_element = nums[0]
        for val in nums:
            max_element = max(abs(val), max_element)

        max_digits = 0
        while max_element > 0:
            max_digits += 1
            max_element = max_element // 10

        place_value = 1


# @lc code=end


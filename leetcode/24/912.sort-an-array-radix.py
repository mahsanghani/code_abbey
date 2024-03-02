#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#
# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        max_element = nums[0]
        for val in nums:
            max_element = max(abs(val), max_element)

        max_digits = 0
        while max_element > 0:
            max_digits += 1
            max_element = max_element // 10

        place_value = 1
        
        def buckets():
            buckets = [[] for i in range(10)]
            for val in nums:
                digit = abs(val) / place_value
                digit = int(digit%10)
                buckets[digit].append(val)

            index = 0
            for digit in range(10):
                for val in buckets[digit]:
                    nums[index] = val
                    index += 1

        for _ in range(max_digits):
            buckets()
            place_value *= 10

        positives = [val for val in nums if val>=0]
        negatives = [val for val in nums if val<0]
        return positives + negatives
# @lc code=end


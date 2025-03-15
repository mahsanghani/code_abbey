class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        missing = 1

        for num in nums:
            if num>0 and missing==num:
                missing += 1

        return missing

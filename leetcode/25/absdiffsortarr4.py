class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        prefix = 0
        total = sum(nums)

        for i,num in enumerate(nums):
            total -= nums[i]
            left = i*nums[i] - prefix
            right = total - (n-i-1)*nums[i]
            res[i] = left + right
            prefix += nums[i]

        return res

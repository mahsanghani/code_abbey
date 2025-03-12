class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        prefix = 0
        res[n-1] = nums[n-1]

        for i in range(n-2,-1,-1):
            res[i] = res[i+1] + nums[i]

        for j in range(n):
            left = (j*nums[j]) - prefix
            right = (res[j+1] if j<n-1 else 0) - ((n-j-1)*nums[j])
            res[j] = left + right
            prefix += nums[j]

        return res

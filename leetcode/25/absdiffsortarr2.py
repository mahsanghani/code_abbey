class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        prefix = [0] * n
        suffix = [0] * n
        prefix[0] = nums[0]
        suffix[n-1] = nums[n-1]

        for i in range(1,n):
            prefix[i] = prefix[i-1] + nums[i]

        for j in range(n-2,-1,-1):
            suffix[j] = suffix[j+1] + nums[j]

        for k in range(n):
            left = (k*nums[k]) - (prefix[k-1] if k>0 else 0)
            right = (suffix[k+1] if k<n-1 else 0) - ((n-k-1)*nums[k])
            res[k] = left + right

        return res

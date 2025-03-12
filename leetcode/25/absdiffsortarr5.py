class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        total_sum = sum(nums)
        left_sum = 0
        res = []

        for i in range(len(nums)):
            right_sum = total_sum - left_sum - nums[i]
            
            left_count = i
            right_count = n - 1 - i
            
            left_total = left_count * nums[i] - left_sum
            right_total = right_sum - right_count * nums[i]

            res.append(left_total + right_total)
            left_sum += nums[i]
        
        return res

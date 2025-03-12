class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        res = []
        
        for i in nums:
            sum = 0
            for j in nums:
                sum += abs(i-j)
            res.append(sum)

        return res

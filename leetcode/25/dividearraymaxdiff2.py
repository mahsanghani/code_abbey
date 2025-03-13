class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        res=[]
        nums.sort()
        
        for i in range(0, len(nums), 3):
            if nums[i+2] - nums[i] > k:
                return []
            res.append(nums[i:i+3])

        return res

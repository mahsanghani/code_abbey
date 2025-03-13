class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        i=0
        res=[]
        nums.sort()

        while i+2<len(nums):
            print(nums[i+2])
            if nums[i+2]-nums[i+1]>k or nums[i+1]-nums[i]>k or nums[i+2]-nums[i]>k:
                return []
            else:
                res.append([nums[i],nums[i+1],nums[i+2]])
            i+=3

        return res

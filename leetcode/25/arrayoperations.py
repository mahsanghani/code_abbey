class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        i=0
        while i<len(nums)-1:
            if nums[i]==nums[i+1]:
                nums[i]*=2
                nums[i+1]=0
                i+=1
            i+=1

        j=0
        zeros=0
        while j<len(nums):
            if nums[j]==0:
                zeros+=1
                nums.pop(j)
                j-=1
            j+=1

        return nums+[0]*zeros

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        dip=0

        for i in range(1,len(nums)):
            if nums[i]<nums[i-1]:
                if dip==1:
                    return False
                else:
                    dip+=1

                if i<2 or nums[i]>=nums[i-2]:
                    nums[i-1] = nums[i]
                else:
                    nums[i] = nums[i-1]
        
        return True
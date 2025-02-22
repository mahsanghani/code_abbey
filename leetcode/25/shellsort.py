class Solution:
    def shellsort(self,nums,n):
        gap = n//2
        while gap>=1:
            for i in range(gap,n):
                temp=nums[i]
                j=i-gap
                while j>=0 and nums[j]>temp:
                    nums[j+gap]=nums[j]
                    j-=gap
                nums[j+gap]=temp
            gap//=2

        return nums
        
    def sortArray(self,nums):
        n = len(nums)
        if n==1:
            return nums
        self.shellsort(nums,n)
        return nums
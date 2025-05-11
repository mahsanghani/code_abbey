class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        for i in range(n):
            if ((i%2==0 and nums[i]>0) or
                (i%2==1 and nums[i]<0)):
                continue

            j=i+1

            while j<n and ((nums[j]>0) == (nums[i]>0)):
                j+=1

            temp = nums[j]

            while j>i:
                nums[j] = nums[j-1]
                j-=1

            nums[i] = temp

        return nums
    
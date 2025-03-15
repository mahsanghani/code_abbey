class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0

        while i<n:
            if nums[i]<=0 or nums[i]>n:
                i+=1
                continue

            index = nums[i]-1
            if nums[i] != nums[index]:
                nums[i], nums[index] = nums[index], nums[i]
            else:
                i+=1

        for i in range(n):
            if nums[i] != i+1:
                return i+1

        return n+1

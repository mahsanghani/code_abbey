class Solution:
    def swap(self,i,j):
        self.nums[i], self.nums[j] = self.nums[j], self.nums[i]

    def wiggleSort(self, nums: List[int]) -> None:
        self.nums = nums
        for i in range(1,len(nums)):
            if i%2==0 and nums[i]>nums[i-1]:
                self.swap(i,i-1)
            if i%2==1 and nums[i]<nums[i-1]:
                self.swap(i,i-1)
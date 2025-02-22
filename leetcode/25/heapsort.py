class Solution:
    def heapify(self,nums,n,i):
        l = (i<<1)+1
        r = (i<<1)+2
        largest=i
        
        if l<n and nums[l]>nums[largest]:
            largest=l

        if r<n and nums[r]>nums[largest]:
            largest=r

        if largest!=i:
            nums[i],nums[largest]=nums[largest],nums[i]
            self.heapify(nums,n,largest)

        # return nums

    def heapsort(self,nums):
        n = len(nums)
        for i in range(n//2-1,-1,-1):
            self.heapify(nums,n,i)

        for j in range(n-1,0,-1):
            nums[0],nums[j]=nums[j],nums[0]
            self.heapify(nums,j,0)

        # return nums

    def sortArray(self,nums):
        if not nums:
            return nums
        self.heapsort(nums)
        return nums
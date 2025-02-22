class Solution:
    def countingsort(self,nums):
        counts = defaultdict(int)
        minval=min(nums)
        maxval=max(nums)

        for num in nums:
            counts[num]+=1

        idx=0
        for num in range(minval,maxval+1):
            while counts[num]>0:
                nums[idx]=num
                idx+=1
                counts[num]-=1

        return nums

    def sortArray(self, nums):
        self.countingsort(nums)
        return nums
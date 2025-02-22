class Solution:
    def countsort(self,nums,n,d):
        count=[0]*10
        for num in nums:
            count[(num//d)%10]+=1
        for i in range(1,10):
            count[i]+=count[i-1]

        res=[0]*n
        for i in range(n-1,-1,-1):
            idx=(nums[i]//d)%10
            res[count[idx]-1]=nums[i]
            count[idx]-=1

        for i in range(n):
            nums[i]=res[i]

        return nums

    def radixsort(self,nums):
        n=len(nums)
        maxval=max(nums)
        d=1
        while maxval//d>0:
            self.countsort(nums,n,d)
            d*=10
        return nums

    def sortArray(self,nums):
        neg = [-num for num in nums if num<0]
        pos = [num for num in nums if num>=0]

        if neg:
            self.radixsort(neg)
            neg = [-num for num in reversed(neg)]

        if pos:
            self.radixsort(pos)

        return neg+pos
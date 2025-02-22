class Solution:
    def merge(self,nums,left,mid,right):
        left_half = nums[left:mid+1]
        right_half = nums[mid+1:right+1]
        i = left
        j = 0
        k = 0

        while j<len(left_half) and k<len(right_half):
            if left_half[j]<=right_half[k]:
                nums[i]=left_half[j]
                j+=1
            else:
                nums[i]=right_half[k]
                k+=1
            i+=1
        while j<len(left_half):
            nums[i]=left_half[j]
            j+=1
            i+=1
        while k<len(right_half):
            nums[i]=right_half[k]
            k+=1
            i+=1

    def mergesort(self,nums,left,right):
        if left==right:
            return nums

        mid = (left+right)//2
        self.mergesort(nums,left,mid)
        self.mergesort(nums,mid+1,right)
        self.merge(nums,left,mid,right)
        return nums

    def sortArray(self,nums:List[int])->List[int]:
        if not nums:
            return nums
        self.mergesort(nums,0,len(nums)-1)
        return nums
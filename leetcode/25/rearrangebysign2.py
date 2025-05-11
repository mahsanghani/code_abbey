class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = []
        neg = []

        for num in nums:
            if num>0:
                pos.append(num)
            else:
                neg.append(num)

        i = 0
        while 2*i<len(nums):
            nums[2*i] = pos[i]
            nums[2*i+1] = neg[i]
            i+=1

        return nums
    
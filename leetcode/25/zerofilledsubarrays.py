class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res=0
        sub=0

        for num in nums:
            if num==0:
                sub+=1
            else:
                sub=0
            res+=sub

        return res

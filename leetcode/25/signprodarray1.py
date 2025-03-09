class Solution:
    def arraySign(self, nums: List[int]) -> int:
        numset = set(nums)
        if 0 in numset:
            return 0
        d = {1:0,-1:0}
        for num in nums:
            if num>0:
                d[1]+=1
            if num<0:
                d[-1]+=1
            if num==0:
                continue
        if d[-1]%2==0:
            return 1
        if d[-1]%2==1:
            return -1
        return 1

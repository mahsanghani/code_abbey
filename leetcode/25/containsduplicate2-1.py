class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d={}

        for i,j in enumerate(nums):
            if j in d and abs(d[j]-i)<=k:
                return True
            else:
                d[j]=i

        return False
    
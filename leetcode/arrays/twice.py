class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        nums2 = sorted(list(set(nums)))
        if nums2[-1]>=2*nums2[-2]:
            return nums.index(nums2[-1])
        return -1

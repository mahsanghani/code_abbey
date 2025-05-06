class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        d=defaultdict(int)
        
        for k,v in nums1:
            d[k]+=v

        for k,v in nums2:
            d[k]+=v

        return [[k,v] for k,v in sorted(d.items())]

import heapq
from collections import defaultdict
from heapq import heapify, heappush, heappop

class Solution:
    def __init__(self) -> None:
        return
    
    def topKFrequent(self, nums, n):
        h=[]
        res=[]
        d=defaultdict(int)

        for num in nums:
            d[num]+=1

        for k,v in d.items():
            heapq.heappush(h,(-v,k))
            
        for _ in range(n):
            res.append(heapq.heappop(h)[1])
        print(res)
        return res
    
s = Solution()
s.topKFrequent([1,1,1,2,2,3],2)
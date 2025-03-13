from collections import Counter

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res=0
        counts = Counter(nums)
        
        for k,v in counts.items():
            if v==1:
                return -1

            threes = v//3
            modulo = v%3

            if modulo == 0:
                res+=threes
            elif modulo == 1:
                res+=threes-1+2
            else:
                res+=threes+1

        return res

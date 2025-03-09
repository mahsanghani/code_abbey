class Solution:
    def partitionString(self, s: str) -> int:
        res=0
        unq=set()

        for c in s:
            if c in unq:
                res+=1
                unq=set()
            unq.add(c)
    
        res+=1
        return res

from collections import defaultdict

class Solution:
    def interchangeableRectangles(self, r: List[List[int]]) -> int:
        res=0
        d=defaultdict(list)

        for e in r:
            d[e[0]/e[1]].append(e)

        for k,v in d.items():
            if len(v)>1:
                res+=(len(v)*(len(v)-1))//2

        return res
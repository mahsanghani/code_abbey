class Solution:
    def interchangeableRectangles(self, r: List[List[int]]) -> int:
        res=0

        for i in range(len(r)):
            for j in range(i+1,len(r)):
                if r[i][0]/r[i][1]==r[j][0]/r[j][1]:
                    res+=1

        return res
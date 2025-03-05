class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        i=0
        j=len(p)
        res=[]
        
        while j<=len(s):
            if Counter(s[i:j])==Counter(p):
                res.append(i)
            i+=1
            j+=1

        return res
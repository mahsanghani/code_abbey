class Solution:
    def maxProduct(self, s: str) -> int:
        res=0
        p={}
        n=len(s)

        def pal(s):
            i=0
            j=len(s)-1
            while i<j:
                if s[i]!=s[j]:
                    return False
                i+=1
                j-=1
            return True
            
        for mask in range(1,1<<n):
            subseq=""
            for i in range(n):
                if mask & (1<<i):
                    subseq+=s[i]

            if pal(subseq):
                p[mask]=len(subseq)

        for m1 in p:
            for m2 in p:
                if m1 & m2 == 0:
                    res = max(res, p[m1]*p[m2])

        return res
class Solution:
    def maxProduct(self, s: str) -> int:
        res=0

        def pal(s):
            i=0
            j=len(s)-1
            while i<j:
                if s[i]!=s[j]:
                    return False
                else:
                    i+=1
                    j-=1
            return True

        def rec(i,s1,s2):
            nonlocal res
            if i==len(s):
                if pal(s1) and pal(s2):
                    res = max(res, len(s1)*len(s2))
                return

            rec(i+1,s1,s2)
            rec(i+1,s1+s[i],s2)
            rec(i+1,s1,s2+s[i])

        rec(0,"","")
        return res
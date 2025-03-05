class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        m = len(p)
        pc = [0]*26
        sc = [0]*26
        res = []
        l = 0

        if m>n:
            return []
        
        for i in range(m):
            pc[ord(p[i])-ord('a')]+=1
            sc[ord(s[i])-ord('a')]+=1

        match = sum(1 for i in range(26) if pc[i]==sc[i])
        
        if match==26:
            res.append(0)

        for r in range(m,n):
            c = ord(s[l])-ord('a')
            if sc[c] == pc[c]:
                match-=1
            
            sc[c]-=1
            l+=1

            if sc[c]==pc[c]:
                match+=1

            c = ord(s[r])-ord('a')

            if sc[c]==pc[c]:
                match-=1
            sc[c]+=1

            if sc[c]==pc[c]:
                match+=1

            if match==26:
                res.append(l)

        return res
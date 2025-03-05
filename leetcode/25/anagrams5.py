class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        m = len(p)
        pc = [0]*26
        res = []
        prefix = [[0]*26 for _ in range(n+1)]
        
        if m>n:
            return res

        for c in p:
            pc[ord(c)-ord('a')]+=1

        for i in range(1,n+1):
            for j in range(26):
                prefix[i][j] = prefix[i-1][j]
            prefix[i][ord(s[i-1])-ord('a')]+=1

        i = 0
        j = m-1

        while j<n:
            valid=True
            for c in range(26):
                if prefix[j+1][c] - prefix[i][c] != pc[c]:
                    valid = False
                    break

            if valid:
                res.append(i)
            
            i+=1
            j+=1
            
        return res
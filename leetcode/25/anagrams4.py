class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        m = len(p)
        # i = 0
        # j = m-1
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

        for j in range(n-m+1):
            valid=True
            for c in range(26):
                if prefix[j+m][c] - prefix[j][c] != pc[c]:
                    valid = False
                    break

            if valid:
                res.append(j)
            
            # i+=1
            # j+=1
            
        return res
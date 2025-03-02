class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        first = [-1]*26
        last = [-1]*26

        for i in range(len(s)):
            j = ord(s[i]) - ord('a')
            if first[j]==-1:
                first[j]=i
            last[j]=i

        res=0
        for ends in range(26):
            if first[ends]==-1:
                continue
            if first[ends]==last[ends]:
                continue
            l=first[ends]
            r=last[ends]
            mask = 0  
            
            for i in range(l+1,r):
                c = ord(s[i]) - ord('a')
                if mask & (1<<c):
                    continue
                mask |= (1<<c)
                res+=1

        return res
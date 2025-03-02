class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n=len(s)
        first=[-1]*26
        last=[-1]*26
        pre=[[0]*26 for _ in range(n+1)]
        
        for i in range(n):
            j = ord(s[i]) - ord('a')
            if first[j]==-1:
                first[j]=i
            last[j]=i
            pre[i+1]=pre[i][:]
            pre[i+1][j]+=1
            
        res=0
        for ends in range(26):
            if first[ends]==-1:
                continue
            if first[ends]==last[ends]:
                continue
            l=first[ends]
            r=last[ends]
            
            for mid in range(26):
                if pre[r][mid] - pre[l+1][mid]>0:
                    res+=1

        return res
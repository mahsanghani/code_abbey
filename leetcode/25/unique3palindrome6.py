class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res=0

        for i in range(26):
            c = chr(ord('a')+i)
            l,r = s.find(c),s.rfind(c)
            if l==-1 or l==r:
                continue
                
            mids = set()
            for j in range(l+1,r):
                mids.add(s[j])
            res+=len(mids)

        return res
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res=set()

        for i in range(len(s)-2):
            for j in range(i+1,len(s)-1):
                for k in range(j+1,len(s)):
                    if s[i]!=s[k]:
                        continue
                    else:
                        res.add(s[i]+s[j]+s[k])

        return len(res)
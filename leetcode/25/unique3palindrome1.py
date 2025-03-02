class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res=set()

        def rec(i,cur):
            if len(cur)==3:
                if cur[0]==cur[2]:
                    res.add(cur)
                return
            if i==len(s):
                return
            rec(i+1,cur)
            rec(i+1,cur+s[i])

        rec(0,"")
        return len(res)
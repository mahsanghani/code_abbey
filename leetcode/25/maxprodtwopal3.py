class Solution:
    def longestPalindromeSubsequence(self, s: str) -> str:
        n = len(s)
        dp = [1]*n
        if n == 0:
            return 0
        for i in range(n-1,-1,-1):
            prev=0
            for j in range(i+1,n):
                tmp = dp[j]
                if s[i]==s[j]:
                    dp[j]=2+prev
                else:
                    dp[j]=max(dp[j-1],dp[j])
                prev=tmp
        return dp[n-1]

    def pal(self, s: str) -> str:
            i=0
            j=len(s)-1
            while i<j:
                if s[i]!=s[j]:
                    return False
                i+=1
                j-=1
            return True

    def maxProduct(self, s: str) -> int:
        res=0
        n=len(s)
        
        for i in range(1,1<<n):
            s1=[]
            s2=[]

            for j in range(n):
                if (i&(1<<j)) != 0:
                    s1.append(s[j])
                else:
                    s2.append(s[j])

            if not self.pal(s1):
                continue

            lps = self.longestPalindromeSubsequence(''.join(s2))
            res = max(res, len(s1)*lps)

        return res
    
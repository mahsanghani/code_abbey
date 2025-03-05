class Solution:
    def palsize(self, s: str, mask: str) -> int:
        i=0
        res=0
        j=len(s)-1

        while i<=j:
            if (mask & (1 << i)) == 0:
                i+=1
            elif (mask & (1 << j)) == 0:
                j-=1
            else:
                if s[i]!=s[j]:
                    return 0
                res+=1 if i==j else 2
                i+=1
                j-=1

        return res

    def longestPalindromeSubsequence(self, s: str, mask: int, dp: List[int]) -> int:
        n=len(s)

        for i in range(n-1,-1,-1):
            if (mask&(1<<i))!=0:
                continue
                
            prev=0
            for j in range(i+1,n):
                tmp=dp[j]
                if (mask&(1<<j))==0 and s[i]==s[j]:
                    dp[j]=2+prev
                else:
                    dp[j]=max(dp[j-1],dp[j])
                prev=tmp
        return dp[-1]

    def maxProduct(self, s: str) -> int:
        res=0
        n=len(s)
        dp=[1]*n

        for i in range(1,1<<n):
            m1=self.palsize(s,i)
            if m1==0:
                continue

            for j in range(n):
                if (i&(1<<j))==0:
                    dp[j]=1
                else:
                    dp[j]=0

            m2=self.longestPalindromeSubsequence(s,i,dp)
            res=max(res,m1*m2)

        return res
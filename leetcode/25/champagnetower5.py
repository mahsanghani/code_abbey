class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [poured] + [0]*query_row

        for row in range(1,query_row+1):
            for i in range(row-1,-1,-1):
                extra = dp[i]-1
                if extra > 0:
                    dp[i] = 0.5*extra
                    dp[i+1] += 0.5*extra
                else:
                    dp[i] = 0

        return min(1, dp[query_glass])

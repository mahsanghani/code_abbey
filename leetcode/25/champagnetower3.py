class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [[0]*(i+1) for i in range(query_row+5)]
        dp[0][0] += poured
        
        for row in range(min(99,query_row+1)):
            for glass in range(row+1):
                excess = (dp[row][glass] - 1.0)/2.0
                if excess > 0:
                    dp[row+1][glass] += excess
                    dp[row+1][glass+1] += excess

        return min(1.0, dp[query_row][query_glass])

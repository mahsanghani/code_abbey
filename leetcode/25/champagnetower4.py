class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        prev = [poured]

        for row in range(1,query_row+1):
            curr = [0]*(row+1)
            for i in range(row):
                extra = prev[i]-1
                if extra > 0:
                    curr[i] += 0.5*extra
                    curr[i+1] += 0.5*extra
            prev = curr

        return min(1, prev[query_glass])

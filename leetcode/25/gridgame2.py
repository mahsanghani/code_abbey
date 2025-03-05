class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        pre0 = grid[0].copy()
        pre1 = grid[1].copy()

        for i in range(1,n):
            pre0[i]+=pre0[i-1]
            pre1[i]+=pre1[i-1]

        res = float("inf")

        for i in range(n):
            top = pre0[-1] - pre0[i]
            bot = pre1[i-1] if i>0 else 0
            rob2 = max(top,bot)
            res = min(res,rob2)

        return res
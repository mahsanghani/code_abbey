class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        res=float("inf")
        cols=len(grid[0])

        top1 = 0
        for i in range(cols):
            top1 += grid[0][i]
            bottom1 = 0
            
            for j in range(i,cols):
                bottom1+=grid[1][j]
                
            top2 = robot2 = 0
            for j in range(cols):
                if j>i:
                    top2+=grid[0][j]
                    
                bottom2 = 0
                for k in range(j,i):
                    bottom2+=grid[1][k]
                robot2 = max(robot2, top2+bottom2)

            res = min(res,robot2)

        return res
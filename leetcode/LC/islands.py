class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows = len(grid)
        cols = len(grid[0])
        visit = set()
        islands=0
        
        def bfs(r,c):
            q=deque()
            visit.add((r,c))
            q.append((r,c))
            
            while q:
                row, col = q.pop()
                directions = [[1,0],[-1,0],[0,1],[0,-1]]
                
                for dr,dc in directions:
                    r = row+dr
                    c = col+dc
                    if (r in range(rows) and 
                        c in range(cols) and 
                        grid[r][c]=="1" and
                        (r,c) not in visit):
                        q.append((r,c))
                        visit.add((r,c))
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]=="1" and (r,c) not in visit:
                    bfs(r,c)
                    islands+=1
                    
        return islands

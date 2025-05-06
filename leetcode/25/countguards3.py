class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        wall = 3
        guard = 2
        guarded = 1
        unguarded = 0

        grid = [[unguarded] * n for _ in range(m)]
        
        for row, col in guards:
            grid[row][col] = guard

        for row, col in walls:
            grid[row][col] = wall

        def updatevisibility(row, col, active):
            if grid[row][col] == guard:
                return True

            if grid[row][col] == wall:
                return False

            if active:
                grid[row][col] = guarded
            
            return active

        for row in range(m):
            active = grid[row][0] == guard
            for col in range(1,n):
                active = updatevisibility(row,col,active)
            active = grid[row][n-1] == guard
            for col in range(n-2,-1,-1):
                active = updatevisibility(row,col,active)

        for col in range(n):
            active = grid[0][col] == guard
            for row in range(1,m):
                active = updatevisibility(row,col,active)
            active = grid[m-1][col] == guard
            for row in range(m-2,-1,-1):
                active = updatevisibility(row,col,active)

        results = 0

        for row in range(m):
            for col in range(n):
                if grid[row][col] == unguarded:
                    results += 1

        return results
    
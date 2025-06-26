# 3. GRID-WISE DFS EXAMPLE
# Problem: Find connected islands in a 2D grid (like in image processing)
class GridGraph:
    def __init__(self, grid):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0]) if grid else 0
        # 4-directional movement (up, down, left, right)
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def is_valid(self, row, col):
        """Check if coordinates are within grid bounds"""
        return 0 <= row < self.rows and 0 <= col < self.cols
    
    def dfs_flood_fill(self, start_row, start_col, target_val, new_val, visited):
        """DFS to flood fill connected regions"""
        if not self.is_valid(start_row, start_col):
            return
        
        if (start_row, start_col) in visited:
            return
        
        if self.grid[start_row][start_col] != target_val:
            return
        
        # Mark as visited and change value
        visited.add((start_row, start_col))
        self.grid[start_row][start_col] = new_val
        
        # Recursively explore all 4 directions
        for dr, dc in self.directions:
            new_row, new_col = start_row + dr, start_col + dc
            self.dfs_flood_fill(new_row, new_col, target_val, new_val, visited)
    
    def count_islands(self):
        """Count connected components of 1s (islands) in a binary grid"""
        if not self.grid:
            return 0
        
        visited = set()
        island_count = 0
        
        for row in range(self.rows):
            for col in range(self.cols):
                if self.grid[row][col] == 1 and (row, col) not in visited:
                    # Found a new island, explore it completely
                    self._dfs_mark_island(row, col, visited)
                    island_count += 1
        
        return island_count
    
    def _dfs_mark_island(self, row, col, visited):
        """Helper DFS to mark all cells of an island as visited"""
        if not self.is_valid(row, col):
            return
        
        if (row, col) in visited:
            return
        
        if self.grid[row][col] != 1:
            return
        
        visited.add((row, col))
        
        # Explore all 4 directions
        for dr, dc in self.directions:
            self._dfs_mark_island(row + dr, col + dc, visited)
    
    def find_largest_connected_region(self):
        """Find size of largest connected region of 1s"""
        if not self.grid:
            return 0
        
        visited = set()
        max_size = 0
        
        for row in range(self.rows):
            for col in range(self.cols):
                if self.grid[row][col] == 1 and (row, col) not in visited:
                    size = self._dfs_region_size(row, col, visited)
                    max_size = max(max_size, size)
        
        return max_size
    
    def _dfs_region_size(self, row, col, visited):
        """Helper DFS to calculate size of connected region"""
        if not self.is_valid(row, col):
            return 0
        
        if (row, col) in visited:
            return 0
        
        if self.grid[row][col] != 1:
            return 0
        
        visited.add((row, col))
        size = 1  # Current cell
        
        # Add sizes from all 4 directions
        for dr, dc in self.directions:
            size += self._dfs_region_size(row + dr, col + dc, visited)
        
        return size

# Example usage
grid_data = [
    [1, 1, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 1, 1]
]

grid_graph = GridGraph([row[:] for row in grid_data])  # Make a copy
print("Grid DFS - Original grid:")
for row in grid_data:
    print(row)

print(f"Number of islands: {grid_graph.count_islands()}")
print(f"Largest connected region size: {grid_graph.find_largest_connected_region()}")

# Demonstrate flood fill
flood_grid = GridGraph([row[:] for row in grid_data])  # Fresh copy
print("\nFlood fill from position (0,0), changing 1s to 9s:")
flood_grid.dfs_flood_fill(0, 0, 1, 9, set())
for row in flood_grid.grid:
    print(row)
    
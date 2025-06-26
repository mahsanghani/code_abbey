# 1. ADJACENCY MATRIX EXAMPLE
# Problem: Find shortest path in a weighted graph using Floyd-Warshall
class AdjacencyMatrixGraph:
    def __init__(self, vertices):
        self.V = vertices
        # Initialize with infinity (large number) for no connection
        self.graph = [[float('inf')] * vertices for _ in range(vertices)]
        
        # Distance from vertex to itself is 0
        for i in range(vertices):
            self.graph[i][i] = 0
    
    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
    
    def floyd_warshall(self):
        """Find shortest paths between all pairs of vertices"""
        dist = [row[:] for row in self.graph]  # Copy matrix
        
        # Try each vertex as intermediate
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        return dist
    
    def has_edge(self, u, v):
        """O(1) edge existence check - major advantage of adjacency matrix"""
        return self.graph[u][v] != float('inf')

# Example usage
matrix_graph = AdjacencyMatrixGraph(4)
matrix_graph.add_edge(0, 1, 5)
matrix_graph.add_edge(0, 3, 10)
matrix_graph.add_edge(1, 2, 3)
matrix_graph.add_edge(2, 3, 1)

print("Adjacency Matrix - Shortest paths:")
shortest_paths = matrix_graph.floyd_warshall()
for i, row in enumerate(shortest_paths):
    print(f"From vertex {i}: {row}")

print(f"Edge (0,1) exists: {matrix_graph.has_edge(0, 1)}")
print(f"Edge (1,0) exists: {matrix_graph.has_edge(1, 0)}")

print("\n" + "="*50 + "\n")

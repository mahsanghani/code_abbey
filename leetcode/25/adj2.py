# 2. ADJACENCY LIST (INBOUND/OUTBOUND DICTIONARIES) EXAMPLE
# Problem: Find connected components in a sparse social network
from collections import defaultdict, deque

class AdjacencyListGraph:
    def __init__(self):
        # Outbound connections: vertex -> list of neighbors
        self.outbound = defaultdict(list)
        # Inbound connections: vertex -> list of vertices pointing to it
        self.inbound = defaultdict(list)
        self.vertices = set()
    
    def add_edge(self, u, v):
        self.outbound[u].append(v)
        self.inbound[v].append(u)
        self.vertices.add(u)
        self.vertices.add(v)
    
    def get_neighbors(self, vertex):
        """O(1) to get list, efficient iteration through neighbors"""
        return self.outbound[vertex]
    
    def get_predecessors(self, vertex):
        """Get vertices that point to this vertex"""
        return self.inbound[vertex]
    
    def find_connected_components(self):
        """Find strongly connected components using DFS"""
        visited = set()
        components = []
        
        def dfs(vertex, component):
            if vertex in visited:
                return
            visited.add(vertex)
            component.append(vertex)
            
            # Visit all neighbors efficiently
            for neighbor in self.get_neighbors(vertex):
                dfs(neighbor, component)
        
        for vertex in self.vertices:
            if vertex not in visited:
                component = []
                dfs(vertex, component)
                if component:
                    components.append(component)
        
        return components
    
    def bfs_shortest_path(self, start, end):
        """BFS leveraging efficient neighbor iteration"""
        if start not in self.vertices or end not in self.vertices:
            return None
        
        queue = deque([(start, [start])])
        visited = {start}
        
        while queue:
            vertex, path = queue.popleft()
            
            if vertex == end:
                return path
            
            # Efficiently iterate through neighbors
            for neighbor in self.get_neighbors(vertex):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, path + [neighbor]))
        
        return None

# Example usage
list_graph = AdjacencyListGraph()
# Add edges to represent a social network
edges = [(0, 1), (1, 2), (2, 0), (3, 4), (4, 5), (6, 7)]
for u, v in edges:
    list_graph.add_edge(u, v)

print("Adjacency List - Connected components:")
components = list_graph.find_connected_components()
for i, comp in enumerate(components):
    print(f"Component {i}: {comp}")

print(f"Neighbors of vertex 1: {list_graph.get_neighbors(1)}")
print(f"Predecessors of vertex 2: {list_graph.get_predecessors(2)}")
print(f"Path from 0 to 2: {list_graph.bfs_shortest_path(0, 2)}")

print("\n" + "="*50 + "\n")

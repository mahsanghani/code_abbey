"""
A simply Python graph class
demonstrating the essential
facts and functions of graphs.
"""


class Graph(object):
    def __init__(self, graph=None):
        """
        initializes a graph object 
        as an empty dictionary
        """
        if graph==None:
            graph = {}
        self.graph = graph

    def vertices(self):
        """
        returns vertices of a graph
        """
        return list(self.graph.keys())
    
    def edges(self):
        """
        returns edges of a graph
        """
        return self.edges()
    
    def add_vertex(self, vertex):
        """
        empty vertex if not in graph
        """
        if vertex not in self.graph:
            self.graph[vertex] = []
            
    def adj(self):
        """
        return adjacency matrix
        """
        return self.graph

    def __str__(self):
        """
        string output vertices + edges
        """
        results = "vertices: "
        for k in self.graph:
            results += str(k) + " "
        results += "\nedges: "
        for edge in self.gen_edges():
            results += str(edge) + " "
        return results
    
    def add_edge(self, edge, weight=1):
        """
        assuming edges are type set, tuple or list
        """
        edge = set(edge)
        (v1,v2) = tuple(edge)
        if v1 in self.graph:
            self.graph[v1][v2] = weight
        else:
            self.graph[v1] = {v2:weight}

        if v2 in self.graph:
            self.graph[v2][v1] = weight
        else:
            self.graph[v2] = {v1:weight}

    def gen_edges(self):
        """
        generating edges of graph w/ 1 or 2 vertices
        """
        edges = []
        for vertex in self.graph:
            for neighbour,weight in self.graph[vertex].items():
                if (neighbour, vertex, weight) not in edges:
                    edges.append([vertex, neighbour, weight])

        return edges

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
        return self.graph
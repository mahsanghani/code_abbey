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
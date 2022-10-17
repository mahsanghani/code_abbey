from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)

    def addEdge(self, source, destination):
        self.graph[source].append(destination)

    def findEdges(self, source):
        return self.graph[source]

    def isReachable(self, source, destination):
        visit = [False] * (self.vertices)
        queue = [source]
        visit[source] = True

        while queue:
            n = queue.pop(0)
            if n == destination:
                return True

            for i in self.graph[n]:
                if not visit[i]:
                    queue.append(i)
                    visit[i] = True

        return False
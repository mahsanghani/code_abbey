class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        targets = collections.defaultdict(list)
        for i, j in sorted(tickets)[::-1]:
            targets[i] += j,
        routes = []

        def visit(airport):
            while targets[airport]:
                visit(targets[airport].pop())
            routes.append(airport)

        visit("JFK")
        return routes[::-1]

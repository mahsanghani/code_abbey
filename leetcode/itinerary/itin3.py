class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        targets = collections.defaultdict(list)
        for i, j in sorted(tickets)[::-1]:
            targets[i] += j,
        routes = []
        stack = ["JFK"]
        while stack:
            while targets[stack[-1]]:
                stack += targets[stack[-1]].pop(),
            routes += stack.pop(),
        return routes[::-1]

#
# @lc app=leetcode id=1584 lang=python3
#
# [1584] Min Cost to Connect All Points
#

# @lc code=start
import heapq
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # map nodes to list of points with [cost,node]
        adj = {i:[] for i in range(len(points))}
        results = 0
        visit = set()
        minheap = [[0,0]]
        # minimum spanning tree is edges = (nodes - 1) no cycles

        for i in range(len(points)):
            x1,y1 = points[i]
            for j in range(i+1,len(points)):
                x2,y2 = points[j]
                dist = abs(x1-x2)+abs(y1-y2)
                adj[i].append([dist,j])
                adj[j].append([dist,i])
        
        # prim's algorithm
        while len(visit)<len(points):
            cost, i = heapq.heappop(minheap)
            if i in visit:
                continue
            results += cost
            visit.add(i)
            for neighbourCost, neighbour in adj[i]:
                if neighbour not in visit:
                    heapq.heappush(minheap, [neighbourCost, neighbour])
        
        return results

# @lc code=end


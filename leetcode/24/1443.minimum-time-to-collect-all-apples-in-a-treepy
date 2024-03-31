#
# @lc app=leetcode id=1443 lang=python3
#
# [1443] Minimum Time to Collect All Apples in a Tree
#
# @lc code=start
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = {i:[] for i in range(n)}

        for k,v in edges:
            adj[k].append(v)
            adj[v].append(k)

        def dfs(cur, par):
            time = 0

            for nei in adj[cur]:
                if nei == par:
                    continue
                childtime = dfs(nei,cur)
                if childtime or hasApple[nei]:
                    time += 2 + childtime
            return time
        return dfs(0,-1)
# @lc code=end


#
# @lc app=leetcode id=261 lang=python3
#
# [261] Graph Valid Tree
#
# @lc code=start
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not n:
            return True

        res = 0
        visit = set()
        adj = {i:[] for i in range(n)}

        for k,v in edges:
            adj[k].append(v)
            adj[v].append(k)

        def dfs(i,j):
            if i in visit:
                return False
            
            visit.add(i)

            for k in adj[i]:
                if k==j:
                    continue
                if not dfs(k,i):
                    return False

            return True

        return dfs(0,-1) and n==len(visit)

# @lc code=end


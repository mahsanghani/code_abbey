#
# @lc app=leetcode id=1494 lang=python3
#
# [1494] Parallel Courses II
#

# @lc code=start
from itertools import combinations
class Solution:
    @lru_cache(None)
    def recurse(self, mask, indeg):
        if not mask:
            return 0
        nodes = [i for i in range(self.n) if mask & 1 << i and indeg[i] == 0]
        results = float("inf")

        for k in combinations(nodes, min(self.k, len(nodes))):
            new_mask = mask
            new_indeg = list(indeg)

            for c in k:
                new_mask ^= 1<<c
                for child in self.adj[c]:
                    new_indeg -= 1

            results = min(results, 1+self.recurse(new_mask, tuple(new_indeg)))
        return results

    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:


# @lc code=end


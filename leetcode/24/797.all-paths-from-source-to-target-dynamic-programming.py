#
# @lc app=leetcode id=797 lang=python3
#
# [797] All Paths From Source to Target
#

# @lc code=start
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        @lru_cache(maxsize=None)
        target = len(graph)-1
        def dp(current):
            if current == target:
                return [[target]]
            
            results = []
            for next_node in graph[current]:
                for path in dp(next_node):
                    results.append([current] + path)

            return results
        
        return dp(0)
# @lc code=end


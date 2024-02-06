#
# @lc app=leetcode id=797 lang=python3
#
# [797] All Paths From Source to Target
#

# @lc code=start
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        results = []
        target = len(graph)-1

        def backtrack(current, path):
            if current == target:
                results.append(list(path))
                return
            
            for next_node in graph[current]:
                path.append(next_node)
                backtrack(next_node, path)
                path.pop()

        path = [0]
        backtrack(0, path)
        return results
# @lc code=end


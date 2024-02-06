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
            return

        path = [0]
        backtrack(0, path)
        return results
# @lc code=end


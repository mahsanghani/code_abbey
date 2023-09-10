#
# @lc app=leetcode id=1791 lang=python3
#
# [1791] Find Center of Star Graph
#

# @lc code=start
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return edges[0][edges[0][1] in edges[1]] 
# @lc code=end


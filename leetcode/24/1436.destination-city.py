#
# @lc app=leetcode id=1436 lang=python3
#
# [1436] Destination City
#
# @lc code=start
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        adj = {d:s for s,d in paths}
        return next(key for key,value in adj.items() if key not in adj.values())
# @lc code=end


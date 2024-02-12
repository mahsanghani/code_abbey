#
# @lc app=leetcode id=1436 lang=python3
#
# [1436] Destination City
#

# @lc code=start
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        routes = {d:s for s,d in paths}
        return next(key for key in routes.keys() if key not in routes.values())
# @lc code=end


#
# @lc app=leetcode id=973 lang=python3
#
# [973] K Closest Points to Origin
#
# @lc code=start
import math
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = []

        def euclidean(x,y):
            return math.sqrt(x**2+y**2)

        for point in points:
            distances.append((euclidean(point[0],point[1]),point))

        distances.sort(key=lambda x:x[0])

        return [point for distance,point in distances[:k]] 
# @lc code=end


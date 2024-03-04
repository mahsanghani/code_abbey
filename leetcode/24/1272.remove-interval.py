#
# @lc app=leetcode id=1272 lang=python3
#
# [1272] Remove Interval
#
# @lc code=start
class Solution:
    def removeInterval(self, inter: List[List[int]], rem: List[int]) -> List[List[int]]:
        results = []
        inter.sort()

        for i in inter:
            if i[0]>=rem[1] or i[1]<=rem[0]:
                results.append([i[0],i[1]])
            else:
                if i[0]<rem[0]:
                    results.append([i[0],rem[0]])
                if i[1]>rem[1]:
                    results.append([rem[1],i[1]])

        return results
# @lc code=end


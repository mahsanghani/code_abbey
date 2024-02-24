#
# @lc app=leetcode id=986 lang=python3
#
# [986] Interval List Intersections
#

# @lc code=start
class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        results = []
        i,j = 0,0

        while i<len(firstList) and j<len(secondList):
            low = max(firstList[i][0], secondList[j][0])
            high = min(firstList[i][1], secondList[j][1])

            if low<=high:
                results.append([low,high])

            if firstList[i][1]<secondList[j][1]:
                i+=1
            else:
                j+=1

        return results
# @lc code=end


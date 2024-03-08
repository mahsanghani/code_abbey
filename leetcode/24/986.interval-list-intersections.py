#
# @lc app=leetcode id=986 lang=python3
#
# [986] Interval List Intersections
#
# @lc code=start
class Solution:
    def intervalIntersection(self, first: List[List[int]], second: List[List[int]]) -> List[List[int]]:
        i,j,results = 0,0,[]

        while i<len(first) and j<len(second):
            low = max(first[i][0],second[j][0])
            high = min(first[i][1],second[j][1])

            if low<=high:
                results.append([low,high])

            if first[i][1]<second[j][1]:
                i+=1
            else:
                j+=1

        return results

# @lc code=end


#
# @lc app=leetcode id=2001 lang=python3
#
# [2001] Number of Pairs of Interchangeable Rectangles
#

# @lc code=start
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        results = 0
        d = Counter(list(map(lambda x: x[0]/x[1], rectangles)))

        for c in d.values():
            if c>1:
                results+=(c*(c-1))//2
        
        return results
# @lc code=end


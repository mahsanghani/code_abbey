#
# @lc app=leetcode id=2194 lang=python3
#
# [2194] Cells in a Range on an Excel Sheet
#

# @lc code=start
class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        results = []
        start = s.split(':')[0]
        stop = s.split(':')[1]
        for i in range(ord(start[0]),ord(stop[0])+1):
            for j in range(int(start[1]),int(stop[1])+1):
                results.append(chr(i)+str(j))
        return results
# @lc code=end


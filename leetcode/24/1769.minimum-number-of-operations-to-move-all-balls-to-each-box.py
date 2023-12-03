#
# @lc app=leetcode id=1769 lang=python3
#
# [1769] Minimum Number of Operations to Move All Balls to Each Box
#

# @lc code=start
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        results = []
        for i in range(len(boxes)):
            total = 0
            for j in range(i):
                if int(boxes[j])==1:
                    total+=abs(i-j)
            for k in range(len(boxes)-1,i,-1):
                if int(boxes[k])==1:
                    total+=abs(i-k)
            results.append(total)
        return results
# @lc code=end


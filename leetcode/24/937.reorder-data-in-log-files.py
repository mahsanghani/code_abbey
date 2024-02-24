#
# @lc app=leetcode id=937 lang=python3
#
# [937] Reorder Data in Log Files
#
# @lc code=start
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        return sorted(logs,key=self.sort)
    def sort(self,logs):
        a,b = logs.split(' ',1)
        if b[0].isalpha():
            return (0,b,a)
        else:
            return (1,None,None)
# @lc code=end


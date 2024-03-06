#
# @lc app=leetcode id=937 lang=python3
#
# [937] Reorder Data in Log Files
#
# @lc code=start
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digits = []
        letters = []

        def sort(logs):
            for log in logs:
                id,rest = log.split(' ',1)
                return (0,rest,id) if rest[0].isalpha() else (1,rest,id)
            
        return sorted(logs,key=sort)
# @lc code=end


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

        def get_key(log):
            id, rest = log.split(" ", maxsplit=1)
            return (0,rest,id) if rest[0].isalpha() else (1,)
        
        return sorted(logs, key=get_key)
# @lc code=end


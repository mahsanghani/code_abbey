#
# @lc app=leetcode id=187 lang=python3
#
# [187] Repeated DNA Sequences
#

# @lc code=start
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = set()
        results = set()

        for i in range(len(s)-9):
            current = s[i:i+10]
            if current not in seen:
                seen.add(current)
            else:
                results.add(current)
        return list(results)
# @lc code=end


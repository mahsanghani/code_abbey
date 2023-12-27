#
# @lc app=leetcode id=2942 lang=python3
#
# [2942] Find Words Containing Character
#
# @lc code=start
class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        results = []

        for i,j in enumerate(words):
            if x in j:
                results.append(i)

        return results
# @lc code=end


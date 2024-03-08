#
# @lc app=leetcode id=819 lang=python3
#
# [819] Most Common Word
#
# @lc code=start
import re
from collections import Counter
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = re.split(r"\W+", paragraph.lower())
        counts = dict(sorted(Counter(words).items(), key=lambda x:x[1], reverse=True))
        return next(key for key in sorted(counts.keys()) if key not in set(banned))
# @lc code=end


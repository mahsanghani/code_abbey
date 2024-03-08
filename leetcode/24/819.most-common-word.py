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
        banned.append("")
        counts = [word for word in words if word not in set(banned)]
        return max(counts,key=counts.count)
# @lc code=end


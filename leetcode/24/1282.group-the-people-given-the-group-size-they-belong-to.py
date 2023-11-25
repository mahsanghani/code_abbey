#
# @lc app=leetcode id=1282 lang=python3
#
# [1282] Group the People Given the Group Size They Belong To
#

# @lc code=start
from collections import Counter
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        results = []
        counter = Counter()
        for i,j in enumerate(groupSizes):
            if j in counter:
                counter[j].append(i)
            else:
                counter[j] = [i]
        for k,v in counter.items():
            while len(v)>k:
                results.append(v[:k])
                v = v[k:]
            results.append(v)
        return results
# @lc code=end


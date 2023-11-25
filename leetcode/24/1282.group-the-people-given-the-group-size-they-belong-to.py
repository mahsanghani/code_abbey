#
# @lc app=leetcode id=1282 lang=python3
#
# [1282] Group the People Given the Group Size They Belong To
#

# @lc code=start
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        results = []
        sizes = {}

        for i,j in enumerate(groupSizes):
            if j in sizes:
                sizes[j].append(i)
            else:
                sizes[j] = [i]

        for k,v in sizes.items():
            while len(v)>k:
                results.append(v[:k])
                v = v[k:]
            results.append(v)
        
        return results
# @lc code=end


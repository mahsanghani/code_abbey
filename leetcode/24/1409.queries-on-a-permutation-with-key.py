#
# @lc app=leetcode id=1409 lang=python3
#
# [1409] Queries on a Permutation With Key
#

# @lc code=start
class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        results = []
        perms = list(range(1,m+1))

        for q in queries:
            results.append(perms.index(q))
            perms.remove(q)
            perms.insert(0,q)

        return results
# @lc code=end


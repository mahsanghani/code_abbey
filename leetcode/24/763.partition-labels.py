#
# @lc app=leetcode id=763 lang=python3
#
# [763] Partition Labels
#

# @lc code=start
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        l,r = 0,0
        results = []
        visit = {j:i for i,j in enumerate(s)}

        for i,j in enumerate(s):
            r = max(r,visit[j])
            if i==r:
                results.append(r-l+1)
                l=r+1
        return results
# @lc code=end


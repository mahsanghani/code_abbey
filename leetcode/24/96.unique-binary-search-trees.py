#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#
# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        trees = [1]*(n+1)
        for nodes in range(2,n+1):
            total = 0
            for root in range(1,nodes+1):
                left = root-1
                right = nodes-root
                total += trees[left] * trees[right]
            trees[nodes] = total
        return trees[n]
# @lc code=end


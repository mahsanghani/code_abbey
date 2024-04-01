#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#
# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        nums = [1]*(n+1)

        for nodes in range(2,n+1):
            total = 0
            for node in range(1,nodes+1):
                left = node-1
                right = nodes-node
                total += nums[left]*nums[right]
            nums[node] = total
        return nums[n]
# @lc code=end


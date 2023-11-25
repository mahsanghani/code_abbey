#
# @lc app=leetcode id=1261 lang=python3
#
# [1261] Find Elements in a Contaminated Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
from collections import deque
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        if not root:
            return
        
        self.set = set()
        queue = collections.deque([[root, 0]])
        while queue:
            n,x = queue.popleft()
            self.set.add(x)
            if n.left:
                queue.append([n.left, 2*x+1])
            if n.right:
                queue.append([n.right, 2*x+2])
        

    def find(self, target: int) -> bool:
        return target in self.set


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
# @lc code=end


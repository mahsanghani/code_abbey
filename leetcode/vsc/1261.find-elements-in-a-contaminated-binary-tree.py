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
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.set = set()
        recover = lambda n,x: [self.set.add(x), recover(n.left,2*x+1), recover(n.right,2*x+2)] if n else None
        recover(root, 0)

    def find(self, target: int) -> bool:
        return target in self.set


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
# @lc code=end


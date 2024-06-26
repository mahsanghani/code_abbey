#
# @lc app=leetcode id=173 lang=python3
#
# [173] Binary Search Tree Iterator
#
# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class BSTIterator:
    def __init__(self, node: Optional[TreeNode]):
        self.stack = []
        while node:
            self.stack.append(node)
            node = node.left

    def next(self) -> int:
        res = self.stack.pop()
        node = res.right

        while node:
            self.stack.append(node)
            node = node.left

        return res.val

    def hasNext(self) -> bool:
        return self.stack != []


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end


#
# @lc app=leetcode id=57 lang=python3
#
# [57] Query Interval
#
# @lc code=start
class TreeNode:
    def __init__(self, start, end, middle) -> None:
        self.start = start
        self.middle = middle
        self.end = end
        self.left = None
        self.right = None

class Solution:
    def __init__(self) -> None:
        self.root = None

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        for start, end in intervals:
            if not self.root:
                self.root = TreeNode(start, end, (start,end)//2)
            else:
                self.add(self.root, start, end)
        
        return self.query(self.root)
# @lc code=end


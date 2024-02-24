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
    
    def add(self, node, start, end):
        if end < node.middle:
            if node.left:
                self.add(node.left, start, end)
            else:
                node.left = TreeNode(start, end, (start+end)//2)
        
        elif start > node.middle:
            if node.right:
                self.add(node.right, start, end)
            else:
                node.right = TreeNode(start, end, (start+end)//2)

        else:
            node.start = min(node.start, start)
            node.end = max(node.end, end)
            
    def query(self, node):
        results = []
        if not node:
            return []
        
        inserted = False
        left = self.query(node.left)
        right = self.query(node.right)

        for l in left:
            if l[1]<node.start:
                results.append(l)
            else:
                results.append([min(l[0],node.start),node.end])
                inserted = True
                break

        if not inserted:
            results.append([node.start, node.end])
        
        for r in right:
            if r[0]<=node.end:
                results[-1][1] = max(node.end, r[1])
            else:
                results.append(r)

        return results
# @lc code=end


#
# @lc app=leetcode id=1628 lang=python3
#
# [1628] Design an Expression Tree With Evaluate Function
#

# @lc code=start
import abc 
from abc import ABC, abstractmethod 
"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""

class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass


"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stack = []
        current = None
        for c in postfix:
            current = TreeNode(c)
            if not c.isdigit():
                current.right = stack.pop()
                current.left = stack.pop()
            stack.append(current)
        return current
		
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
        
# @lc code=end


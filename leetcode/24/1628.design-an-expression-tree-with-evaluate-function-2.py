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

class TreeNode(Node):
    def __init__(self, left, right):
        # self.value = value
        self.left = left
        self.right = right

    def evaluate(self) -> int:
        pass

class Plus(TreeNode):
    def evaluate(self) -> int:
        return self.left.evaluate() + self.right.evaluate()
    
class Minus(TreeNode):
    def evaluate(self) -> int:
        return self.left.evaluate() - self.right.evaluate()
    
class Mul(TreeNode):
    def evaluate(self) -> int:
        return self.left.evaluate() * self.right.evaluate()
    
class Div(TreeNode):
    def evaluate(self) -> int:
        return self.left.evaluate() // self.right.evaluate()
    
class Num(Node):
    def __init__(self, value):
        self.value = value
    def evaluate(self) -> int:
        return self.value

"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stack = []
        operators = {'+': Plus, '-': Minus, '*': Mul, '/': Div}
        for token in postfix:
            if token in operators:
                R = stack.pop()
                L = stack.pop()
                stack.append(operators[token](L, R))
            else:
                stack.append(Num(int(token)))
        return stack[0]
		
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
        
# @lc code=end


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

class BinaryNode(Node):
    """base class for binary nodes"""
    def __init__(self, _left, _right):
        self.left = _left
        self.right = _right

    def evaluate(self) -> int:
        pass

class Plus(BinaryNode):
    def evaluate(self) -> int:
        return self.left.evaluate() + self.right.evaluate()

class Minus(BinaryNode):
    def evaluate(self) -> int:
        return self.left.evaluate() - self.right.evaluate()

class Mul(BinaryNode):
    def evaluate(self) -> int:
        return self.left.evaluate() * self.right.evaluate()

class Div(BinaryNode):
    def evaluate(self) -> int:
        return self.left.evaluate() // self.right.evaluate()

class Num(Node):
    def __init__(self, _value):
        self.value = _value
    
    def evaluate(self) -> int:
        return self.value

"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        operators = {'+': Plus, '-': Minus, '*': Mul, '/': Div}
        stack = []
        for token in postfix:
            if token in operators:
                right = stack.pop()
                left = stack.pop()
                stack.append(operators[token](left,right))
            else:
                stack.append(Num(int(token)))

        return stack[0]
		
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""

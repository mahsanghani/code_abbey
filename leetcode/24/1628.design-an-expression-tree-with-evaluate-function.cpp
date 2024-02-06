//
// @lc app=leetcode id=1628 lang=cpp
//
// [1628] Design an Expression Tree With Evaluate Function
//

// @lc code=start
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
};

/**
 * Definition for a node with a numeric value.
*/
class NumNode : public Node {
public:
    NumNode(int val) : _val (val) {}
    int evaluate() const;
private:
    int _val;
};

int NumNode::evaluate() const {
    return _val;
};

/**
 * Definition for the interface of a node with an operator.
*/
class OpNode : public Node {
public:
    OpNode(Node* left, Node* right) : left (left), right (right) {}
    ~OpNode();
protected:
    Node* const left;
    Node* const right;
};
OpNode::~OpNode() {
    delete left;
    delete right;
};

/**
 * Definition for a node with add operator.
*/
class AddOpNode : public OpNode {
public:
    AddOpNode(Node* left, Node* right): OpNode(left, right) {}
    int evaluate() const;
};
int AddOpNode::evaluate() const {
    return left->evaluate() + right->evaluate();
};

/**
 * Definition for a node with subtract operator.
*/
class SubtractOpNode : public OpNode {
public:
    SubtractOpNode(Node* left, Node* right): OpNode(left, right) {}
    int evaluate() const;
};
int SubtractOpNode::evaluate() const {
    return left->evaluate() - right->evaluate();
};

/**
 * Definition for a node with multiply operator.
*/
class MultiplyOpNode : public OpNode {
public:
    MultiplyOpNode(Node* left, Node* right): OpNode(left, right) {}
    int evaluate() const;
};
int MultiplyOpNode::evaluate() const {
    return left->evaluate() * right->evaluate();
};

/**
 * Definition for a node with a divide operator.
*/
class DivideOpNode : public OpNode {
public:
    DivideOpNode(Node* left, Node* right): OpNode(left, right) {}
    int evaluate() const;
};
int DivideOpNode::evaluate() const {
    return left->evaluate() / right->evaluate();
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
private:
    Node* nodeCreate(string op, Node* left, Node* right) {
        switch (op[0]) {
            case '+':
                return new AddOpNode(left, right);
            case '-':
                return new SubtractOpNode(left, right);
            case '*':
                return new MultiplyOpNode(left, right);
            case '/':
                return new DivideOpNode(left, right);
            default:
                return NULL;
        }
    }

    int toInt(string &x) {
        int results = 0;
        for (char c : x) {
            results = results * 10 + (c - '0');
        }
        return results;
    }

public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node *> curStack;
        for(auto &token : postfix) {
            if(isdigit(token[0])) {
                curStack.push(new NumNode(toInt(token)));
            }
            else {
                auto R = curStack.top(); curStack.pop();
                auto L = curStack.top(); curStack.pop();
                curStack.push(nodeCreate(token, L, R));
            }
        }
        return curStack.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
// @lc code=end


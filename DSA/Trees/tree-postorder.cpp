//
// Created by Ahsan Ghani on 2022-07-22.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL)
        {
            return {};
        }
        vector<int> results;
        stack<Node*>  stack;
        stack.push(root);
        while(!stack.empty())
        {
            Node* temp = stack.top();
            stack.pop();
            for(int i=0; i<temp->children.size(); i++)
            {
                stack.push(temp->children[i]);
            }
            results.push_back(temp->val);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
//
// Created by Ahsan Ghani on 2022-07-22.
//


/*
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
*/

class Solution {
public:
    vector<int> results;
    vector<int> preorder(Node* root) {
        if(!root)
        {
            return results;
        }
        results.push_back(root->val);
        for(int i=0; i<(root->children).size(); i++)
        {
            preorder(root->children[i]);
        }
        return results;
    }
};
//
// Created by Ahsan Ghani on 2022-07-22.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> stack;
        if(root==NULL)
        {
            return preorder;
        }
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode* current = stack.top();
            stack.pop();
            preorder.push_back(current->val);
            if(current->right != NULL)
            {
                stack.push(current->right);
            }
            if(current->left != NULL)
            {
                stack.push(current->left);
            }
        }
        return preorder;
    }
};
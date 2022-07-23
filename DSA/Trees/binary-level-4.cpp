//
// Created by Ahsan Ghani on 2022-07-23.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(!root)
        {
            return results;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int queue_size = queue.size();
            vector<int> row;
            while(queue_size--)
            {
                TreeNode* temp = queue.front();
                queue.pop();
                row.push_back(temp->val);
                if(temp->left)
                {
                    queue.push(temp->left);
                }
                if(temp->right)
                {
                    queue.push(temp->right);
                }
            }
            results.push_back(row);
        }
        return results;
    }
};
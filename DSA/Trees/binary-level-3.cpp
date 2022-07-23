//
// Created by Ahsan Ghani on 2022-07-23.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
        if (!root)
        {
            return results;
        }
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty())
        {
            vector<int> row;
            int queue_size = queue.size();
            for (int i=0; i<queue_size; i++)
            {
                TreeNode* current = queue.front();
                queue.pop_front();
                row.push_back(current->val);
                if (current->left)
                {
                    queue.push_back(current->left);
                }
                if (current->right)
                {
                    queue.push_back(current->right);
                }
            }
            results.push_back(row);
        }
        return results;
    }
};
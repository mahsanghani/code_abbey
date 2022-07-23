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
    vector<vector<int>> results;
    void DFS(TreeNode* root, int level)
    {
        if(!root)
        {
            return;
        }
        if(level==results.size())
        {
            results.push_back(vector<int> ());
        }
        results[level].push_back(root->val);
        DFS(root->left, level+1);
        DFS(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        DFS(root,0);
        return results;
    }
};
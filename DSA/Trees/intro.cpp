//
// Created by Ahsan Ghani on 2022-07-03.
//
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    return 0;
}
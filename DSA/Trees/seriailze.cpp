//
// Created by Ahsan Ghani on 2022-07-05.
//
#include <iostream>
#define MARKER -1

struct Node
{
    int key;
    struct Node* left, *right;
};

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

void serialize(Node *root, FILE *fp)
{
    if(root==NULL)
    {
        fprintf(fp,"%d",MARKER);
        return;
    }

    fprintf(fp, "%d", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deserialize(Node *&root, FILE *fp)
{
    int val;
    if(!fscanf(fp, "%d", &val) || val==MARKER)
        return;

    root = newNode(val);
    deserialize(root->left, fp);
    deserialize(root->right, fp);
}

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

void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d", root->key);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    FILE *fp = fopen("tree.txt", "w");
    if(fp==NULL)
    {
        puts("Could not open file");
        return 0;
    }

    serialize(root, fp);
    fclose(fp);

    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deserialize(root1, fp);

    printf("Inorder traversal of the tree constructed from file: \n");
    inorder(root1);

    return 0;
}

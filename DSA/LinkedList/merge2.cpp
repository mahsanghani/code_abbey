//
// Created by Ahsan Ghani on 2022-07-15.
//
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printList(struct Node* node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node* mergeUtil(struct Node* h1, struct Node* h2)
{
    if(!h1->next)
    {
        h1->next = h2;
        return h1;
    }

    struct Node *current1 = h1, *next1 = h1->next;
    struct Node *current2 = h2, *next2 = h2->next;

    while(next1 && current2)
    {
        if((current2->data) >= (current1->data) &&
        (current2->data) <= (next1->data))
        {
            next2 = current2->next;
            current1->next = current2;
            current2->next = next1;

            current1 = current2;
            current2 = next2;
        }
        else
        {
            if(next1->next)
            {
                next1 = next1->next;
                current1 = current1->next;
            }
            else
            {
                next1->next = current2;
                return h1;
            }
        }
    }
    return h1;
}


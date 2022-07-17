//
// Created by Ahsan Ghani on 2022-07-15.
//

// Head recursive C++ program
// to reverse a linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(){};
    Node(int val) : data(val), next(NULL) {};
};

void reverseUtil(Node* current, Node* previous, Node** headref)
{
    if(current->next == NULL)
    {
        *headref = current;
        current->next = previous;
        return;
    }
    reverseUtil(current->next, current, headref);
    current->next = previous;
}

void reverse(Node** headref)
{
    if(*headref == NULL || (*headref)->next == NULL)
    {
        return;
    }
    reverseUtil(*headref, NULL, headref);
}

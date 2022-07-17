//
// Created by Ahsan Ghani on 2022-07-15.
//

// A simple and tail recursive
// C++ program to reverse
// a linked list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void reverseUtil(Node* current, Node* previous, Node** head);

void reverse(Node** head)
{
    if(!head)
    {
        return;
    }
    reverseUtil(*head, NULL, head);
}


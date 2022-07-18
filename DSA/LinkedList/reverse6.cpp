//
// Created by Ahsan Ghani on 2022-07-15.
//

// 1. Create a linked list.
// 2. Count the number of nodes present in the Linked List
// 3. Initialize an array with the size of the count.
// 4. Store the elements of the Linked list in array
// 5. Print the array from the last index to the first.

#include <iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
} node;

node* head = NULL;

int count(node* head)
{
    node* p = head;
    int k = 1;
    while(p != NULL)
    {
        p = p->next;
        k++;
    }
    return k;
}


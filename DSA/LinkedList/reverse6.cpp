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

node* ll_reverse(node* head)
{
    node* p= head;
    long int i = count(head);
    long int j = 1;
    long int arr[i];
    while(i && p != NULL)
    {
        arr[j++] = p->val;
        p = p->next;
        i--;
    }
    j--;
    while(j)
    {
        cout << arr[j--] << " " << endl;
    }
    return head;
}

node* insert_end(node* head, int data)
{
    node *q = head;
    node *p = (node*)malloc(sizeof(node));
    p->val = data;
    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    p->next = NULL;
    return head;
}

node* create_ll(node* head, int data)
{
    node* p = (node*)malloc(sizeof(node));
    p->val = data;
    if(head == NULL)
    {
        head = p;
        p->next = NULL;
        return head;
    }
    else
    {
        head = insert_end(head, data);
        return head;
    }
}


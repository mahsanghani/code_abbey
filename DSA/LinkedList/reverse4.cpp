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

void push(Node** headref, int x)
{
    Node* newptr = new Node(x);
    if(*headref == NULL)
    {
        *headref = newptr;
    }
    else
    {
        Node* temp = *headref;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newptr;
    }
}

void print(Node* headref)
{
    while(headref != NULL)
    {
        cout << headref->data << " " << endl;
        headref = headref->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    cout << "Given Linked List." << endl;
    print(head);
    reverse(&head);
    cout << "Reversed Linked List." << endl;
    print(head);
    return 0;
}
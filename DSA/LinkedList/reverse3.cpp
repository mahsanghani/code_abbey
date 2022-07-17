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

void reverseUtil(Node* current, Node* previous, Node** head)
{
    if(!current->next)
    {
        *head = current;
        current->next = previous;
        return;
    }
    Node* next = current->next;
    current->next = previous;
    reverseUtil(next, current, head);
}

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printlist(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " " << endl;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    cout << "Given linked list\n";
    printlist(head1);
    reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}

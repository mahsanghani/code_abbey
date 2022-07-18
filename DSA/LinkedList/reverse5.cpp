//
// Created by Ahsan Ghani on 2022-07-15.
//

// Store the nodes(values and address) in the stack until all the values are entered.
// Once all entries are done, Update the Head pointer to the last location(i.e the last value).
// Start popping the nodes(value and address) and store them in the same order until the stack is empty.
// Update the next pointer of last Node in the stack by NULL.

#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void reverseLL(Node** head)
{
    stack<Node*> s;
    Node* temp = *head;
    while(temp->next != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }

    *head = temp;
    while(!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void printlist(Node* temp)
{
    while(temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
}

void insert_back(Node** head, int value)
{
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
        return;
    }
    else
    {
        Node* last_node = *head;
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = temp;
        return;
    }
}

int main()
{
    Node* head = NULL;
    insert_back(&head,1);
    insert_back(&head,2);
    insert_back(&head,3);
    insert_back(&head,4);
    insert_back(&head,5);
    cout << "Given linked list: " << endl;
    printlist(head);
    reverseLL(&head);
    cout << "Reversed linked list: " << endl;
    printlist(head);
    return 0;
}


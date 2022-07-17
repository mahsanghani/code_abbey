//
// Created by Ahsan Ghani on 2022-07-15.
//

// Initialize three pointers prev as NULL, curr as head and next as NULL.
// Iterate through the linked list. In loop, do following.
// Before changing next of current,
// store next node
// next = curr->next
// Now change next of current
// This is where actual reversing happens
// curr->next = prev
// Move prev and curr one step forward
// prev = curr
// curr = next

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    { head = NULL; }

    void reverse()
    {
        Node* current = head;
        Node *previous = NULL;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    void print()
    {
        struct Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList l1;
    l1.push(20);
    l1.push(4);
    l1.push(15);
    l1.push(85);

    cout << "Given linked list." << endl;
    l1.print();
    l1.reverse();

    cout << "Reversed Linked List." << endl;
    l1.print();
    return 0;
}

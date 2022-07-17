//
// Created by Ahsan Ghani on 2022-07-15.
//

// 1) Divide the list in two parts - first node and
// rest of the linked list.
// 2) Call reverse for the rest of the linked list.
// 3) Link rest to first.
// 4) Fix head pointer

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
    {
        head = NULL;
    }

    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* rest = reverse(head->next);
        head->next = NULL;

        return rest;
    }
};
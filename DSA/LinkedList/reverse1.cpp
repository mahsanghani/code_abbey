//
// Created by Ahsan Ghani on 2022-07-15.
//
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

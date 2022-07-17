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


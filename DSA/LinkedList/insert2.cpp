//
// Created by Ahsan Ghani on 2022-07-02.
//
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void insertahead(node*& head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;
}
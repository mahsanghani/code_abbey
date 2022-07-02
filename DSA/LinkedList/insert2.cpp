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

void insertafter(node* head, int key, int val){
    node* n = new node(val);
    if (key == head->data){
        n->next = head->next;
        head->next = n;
        return;
    }
    node* temp = head;
    while(temp->data != key){
        temp = temp->next;
        if(temp==NULL){
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}
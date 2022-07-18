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


/* Program to remove duplicates in an unsorted
   linked list */
#include <bits/stdc++.h> 
using namespace std;

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

// Utility function to create a new Node 
struct Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(struct Node *start)
{
	// Hash to store seen values 
	unordered_set<int> seen;

	/* Pick elements one by one */
	struct Node *curr = start;
	struct Node *prev = NULL;
	while (curr != NULL)
	{
		// If current value is seen before 
		if (seen.find(curr->data) != seen.end())
		{
			prev->next = curr->next;
			delete (curr);
		}
		else
		{
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above function */
int main()
{
	/* The constructed linked list is:
	 10->12->11->11->12->11->10*/
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
		newNode(11);
	start->next->next->next->next->next->next =
		newNode(10);

	printf("Linked list before removing duplicates : \n");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates : \n");
	printList(start);

	return 0;
}
/*
METHOD 3 (Use Hashing)
We traverse the link list from head to end. For every newly encountered element, 
we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table.

Output:
Linked list before removing duplicates :
10 12 11 11 12 11 10
Linked list after removing duplicates :
10 12 11
Thanks to bearwang for suggesting this method.

Time Complexity : O(n) on average(assuming that hash table access time is O(1) on average).
*/
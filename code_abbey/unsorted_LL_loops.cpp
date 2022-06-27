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
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	/* Pick elements one by one */
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		/* Compare the picked element with rest
		   of the elements */
		while (ptr2->next != NULL)
		{
			/* If duplicate then delete it */
			if (ptr1->data == ptr2->next->data)
			{
				/* sequence of steps is important here */
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else /* This is tricky */
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
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

/* Druver program to test above function */
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

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);

	return 0;
}
/*
METHOD 1 (Using two loops)
This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements.

Output:
Linked list before removing duplicates :
10 12 11 11 12 11 10
Linked list after removing duplicates :
10 12 11
Time Complexity : O(n ^ 2)

METHOD 2 (Use Sorting)
In general, Merge Sort is the best - suited sorting algorithm for sorting linked lists efficiently.
1) Sort the elements using Merge Sort.We will soon be writing a post about sorting a linked list.O(nLogn)
2) Remove duplicates in linear time using the algorithm for removing duplicates in sorted Linked List.O(n)

Please note that this method doesn’t preserve the original order of elements.

Time Complexity : O(nLogn)
*/
/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2) {
	if (!*head1 && !*head2)
	     return -1;
	struct node *temp = (*head1)->next;
	int count1 = 0, count2 = 0;
	while (temp->next != (*head1))
	{
		count1++;
		temp = temp->next;
	}
	temp->next = NULL;
	temp = (*head2)->next;
	while (temp->next != (*head2))
	{
		count2++;
		temp = temp->next;
	}
	temp->next = NULL;
	temp = *head1;
	struct node *temp2 = *head2;
	if (!temp) 
		return count1;
	if (!temp2) 
		return count2;

	node *head;
	if (temp->data < temp2->data) {
		head = temp;
	}
	else {
		head = temp2;
		temp2 = temp;
		temp = head;
	}
	while (temp->next && temp2) {
		if (temp->next->data > temp2->data) {
			node *tmp = temp->next;
			temp->next = temp2;
			temp2 = tmp;
		}
		temp = temp->next;
	}
	if (!temp->next) temp->next = temp2;
	temp2->next = head;
	*head1 = head;
	temp = (*head1)->next;
	int count = 0;
	while (temp->next != (*head1))
	{
		temp = temp->next;
		count++;
	}
	if (count > 0)
		return count + 2;
	return -1;
}
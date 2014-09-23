/* Insert a node in a linked list */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int data;
	struct node *next;
	} node;

/* Inserts a new node at the beginning of a node */
void push(node **head, int data) {
	/* Create a new node */
	node *newNode = (node *)malloc(sizeof(node));
	
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

/* Insert a new node at the end of the linked list */
void append(node **head, int data) {
	/* If the list is empty then the node should be inserted at the beginning */
	if (*head == NULL)
		push(head,data);

	else {
		node *headRef = *head;
		/* Traverse to the end of the linked list */
		while(headRef->next != NULL) {
			headRef = headRef->next;
		}
		node *newNode = (node *)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = NULL;
		/* Add the node at the end of the node */
		headRef->next = newNode;
	}
}		

int printList(node *head) {
	if(head == NULL)
		return -1;

	else {
		while(head != NULL) {
			printf("Data is %d\n", head->data);
			head = head->next;
			}
	return 0;
	}
}

int main() {
	node *head = NULL;

	append(&head,1);
	append(&head,2);
	append(&head,3);
	append(&head,4);

	printList(head);

	return 0;
}

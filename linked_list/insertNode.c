/* Insert a listNode in a linked list */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listNode {
	int data;
	struct listNode *next;
	} listNode;

/* Inserts a new listNode at the beginning of a listNode */
void push(listNode **head, int data) {
	/* Create a new listNode */
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

/* Insert a new listNode at the end of the linked list */
void append(listNode **head, int data) {
	/* If the list is empty then the listNode should be inserted at the beginning */
	if (*head == NULL)
		push(head,data);

	else {
		listNode *headRef = *head;
		/* Traverse to the end of the linked list */
		while(headRef->next != NULL) {
			headRef = headRef->next;
		}
		listNode *newNode = (listNode *)malloc(sizeof(listNode));
		newNode->data = data;
		newNode->next = NULL;
		/* Add the listNode at the end of the listNode */
		headRef->next = newNode;
	}
}		

int insertNode(listNode **head, int pos, int data) {
	listNode *current = *head;
	int i = 0;
	while((i < pos - 2) && (current->next != NULL)) {
		current = current->next;
		++i;
	}

	/* There are not enough elements in linked list */
	if(i != pos-2) {
		return -1;
	}

	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = current->next;
	current->next = newNode;

	return 0;
}
int printList(listNode *head) {
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
	int i = 0;
	listNode *head = NULL;
	
	for(i=0;i<10;i++)
		//append(&head,i);
		push(&head,i);
	
	/*if(insertNode(&head,12,15) == -1) {
		printf("Can't insert listNode\n");
		return -1;
	}*/

	printList(head);

	return 0;
}

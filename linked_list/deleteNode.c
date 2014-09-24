#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listNode {
		int data;
		struct listNode *next;
} listNode;

/* Creates a new linked list node */
listNode *getNode() {
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = -1;
	newNode->next = NULL;

	return newNode;
}

void push(listNode **head, int data) {
	listNode *newNode = getNode();
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

/* Deletes a node identified using the key value */
int deleteNode(listNode **head, int key) {
	listNode *current = *head;
	
	/* Check if the list is empty */
	if(*head == NULL)
		return -1;	
	
	/* Check if the first node contains the key */
	if((*head)->data == key) {
		listNode *temp = *head;
		*head = (*head)->next;
		free(temp);
		return 0;
	}
	
	/* Traverse the linked list to locate the element to be deleted */
	while(current->next != NULL && current->next->data != key) {
		current = current->next;
	}	

	/* The list does not contain the node to be deleted */
	if(current->next == NULL)
		return -2;

	/* Delete the node from the list */
	if(current->next->data == key) {
		listNode *temp = current->next;
		current->next = current->next->next;
		free(temp);
		return 0;
	}
}

int printList(listNode *head) {
	/* The list should not be empty */
	if(head == NULL)
		return -1;

	while(head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main() {
	listNode *head = NULL;
	int i = 0;
	
	for(i=0; i < 10; i++)
		push(&head,i);

	if(deleteNode(&head,7) < 0) {
		printf("Can't delete the element\n");
		return 0;
	}
	
	printList(head);

	return 0;
}

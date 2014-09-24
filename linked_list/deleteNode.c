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

int deleteNode(listNode **head, int key) {
	listNode *current = *head;
	
	/* Check if the list is empty */
	if(*head == NULL)
		return -1;	
	
	if((*head)->data == key) {
		listNode *temp = *head;
		*head = (*head)->next;
		free(temp);
		return 0;
	}

	while(current->next != NULL && current->next->data != key) {
		current = current->next;
	}	

	if(current->next == NULL)
		return -2;
	printf("Deleting a node\n");
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

	if(deleteNode(&head,13) < 0) {
		printf("Can't delete the element\n");
		return 0;
	}
	
	printList(head);

	return 0;
}

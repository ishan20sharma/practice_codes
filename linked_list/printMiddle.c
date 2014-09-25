#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listNode {
	int data;
	struct listNode *next;
}listNode;

/* Prints the middle element of the linked list */
int printMiddle(listNode *head) {
	listNode *slowP = head;
	listNode *fastP = head;
	
	/* Check if the list is null */
	if(head == NULL)
		return -1;

	while(fastP != NULL && fastP->next != NULL) {
		slowP = slowP->next;
		fastP = fastP->next->next;
	}

	return slowP->data;
}

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

/* Prints the linked list */
int printList(listNode *head) {
	if(head == NULL)
		return -1;

	while(head != NULL) {
		printf("%d\n",head->data);
		head = head->next;
	}
	return 0;
}

int main() {
	listNode *head = NULL;
	int i = 0;
	int middle;

	for(i=0; i<11;i++)
		push(&head,i);

	printList(head);

	middle = printMiddle(head);
	
	if(middle >= 0)
		printf("Middle element is %d\n",middle);

	return 0;
}

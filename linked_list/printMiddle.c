#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listNode {
	int data;
	struct listNode *next;
}listNode;

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

	for(i=0; i<10;i++)
		push(&head,i);

	printList(head);

	return 0;
}

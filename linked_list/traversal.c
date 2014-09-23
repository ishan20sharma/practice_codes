/* Code to traverse a linked list */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defines a node of a linked lis */
typedef struct node {
	int data;
	struct node *next;
	} node;


/* Traverses the linked list in O(n) time */
int traverseList(node *head) {
	/* If the list is empty return -1 */
	if (head->next == NULL)
		return -1;

	else {
		while(head->next != NULL) {
			printf("Data is %d\n", head->data);
			head = head->next;
		}
		return 0;
	}
}
		
int main() 
{
	node *head = (node *)(malloc(sizeof(node)));
	node *second = (node *)(malloc(sizeof(node)));
	node *third = (node *)(malloc(sizeof(node))) ;
	node *fourth = (node *)(malloc(sizeof(node))) ;

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;
	
	if(traverseList(head) == -1) {
		printf("List is empty");
		return -1;
	}

	return 0;
}

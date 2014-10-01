#include<iostream>


using namespace std;

struct ListNode {
	int data;
	ListNode *next;
};

class singlyll {
	ListNode *head;
	ListNode *getNode(int data);

	public:
	singlyll();
	int printList();
	void insertHead(int data);
	void insertEnd(int data);
	int insertAt(int index, int data);

};

/* Default Constructor */
singlyll::singlyll() {
	head = NULL;
}

/* Creates a list node */
ListNode *singlyll::getNode(int data) {
	ListNode *temp = new ListNode;

	if(!temp) {
		cout << "Can't create a new node" <<endl;
		return NULL;
	}

	temp->data = data;
	temp->next = NULL;

	return temp;
}

/* Inserts an element at the head of the linked list */
void singlyll::insertHead(int data) {
	ListNode *newNode = getNode(data);

	newNode->next = head;
	head = newNode;
}

/* Inserts an element at the end of the linked list */
void singlyll::insertEnd(int data) {
	ListNode * current = head;
	ListNode *newNode = getNode(data);

	/* If the list is empty then the element will be inserted as the first element */
	if(head == NULL){
		newNode->next = head;
		head = newNode;
		return;
	}
	
	/* Traverse to the end of the linked list */
	for(current; current->next; current++)
		;

	current->next = newNode;	
}

/* Inserts the element at a given index */
int singlyll::insertAt(int index, int data) {
	ListNode *current = head;
	ListNode *newNode = getNode(data);

	/* Check if the node is to be inserted at the first position */
	if(head == NULL && index ==1) {

	}

	return 1;
}

/* Prints the singly linked list */
int singlyll::printList() {
	ListNode *current = head;
	
	if(current == NULL) {
		cout << "List is empty" << endl;
		return 0;
	}

	for(current; current; current = current->next) {
		cout << current->data << endl;
	}
	
	return 1;
}


int main() {
	singlyll list;

	for(int i =0; i<50; i++) {
		//list.insertHead(i);
		list.insertEnd(i);
	}

	list.printList();

	return 0;
}

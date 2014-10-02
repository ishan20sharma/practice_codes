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
	int insertSorted(); /* Insert element in a sorted fashion */
	int deleteHead();
	int deleteEnd();
	int deleteAt(int index);
	int deleteElement(int data);
	int printMiddle();
	int checkCycle();
	int removeCycle(); /* Removes a cycle from the linked list */
	int detectIntersection(); /* Get the intersection point of of two linked list */
	int preintReverse(); /* Prints the element of linked list in reverse order */
	int reverseUsingRecursion(); /* Reverse a linked list using recursion */
	int removeDuplicates(); /* Removes duplicate elements */
	int deleteAlternateNodes(); /* Delete alternate nodes of a linked list */
	int reverseKNodes(); /* Reverse every k nodes of a linked list */
	int rotateKNodes(); /* Rotate linked list by K nodes */
	int mergeAtAlternate(); /* Merge a linked list into another list at alternate positions */
	int printNFromEnd(); /* Print nth node from the end */
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
	int count = 1;

	/* Check if the node is to be inserted at the first position */
	if(head == NULL && index != 1) {
		return 0;
	}
	else if (index == 1) {
		newNode->next = head;
		head = newNode;
		return 1;
	}

	/* Traverse the linked list to locate the index position */
	for(current; (current->next != NULL) && (count < index - 1); ++count, current = current->next) {
		;
	}

	if(count == index -1) {
		cout << "Inserting newnode at index-- " << count+1 << endl;
		newNode->next = current->next;
		current->next = newNode;
		cout << "Node successfully inserted" << endl;
		return 1;
	}	
	
	return 0;
}

int singlyll::printMiddle() {
	ListNode *slow = head, *fast = head;

	if(head == NULL) {
		cout << "list is empty" << endl;
		return 0;
	}

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "Middle element is: " << slow->data << endl;

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
	list.printMiddle();
	//list.insertAt(56,16);

	//list.printList();

	return 0;
}

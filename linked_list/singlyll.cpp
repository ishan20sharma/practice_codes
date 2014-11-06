#include<iostream>

using namespace std;

struct ListNode {
	int data;
	ListNode *next;
};

class singlyll {
	ListNode *head;
	ListNode *getNode(int data);
	
	void auxPrintReverse(ListNode *root);
	ListNode *auxReverseUsingRecursion(ListNode *);
	ListNode *auxReverseKNodesRecursively(ListNode *root, const int &k);
	ListNode *auxMergeSortedList(ListNode *l1, ListNode *l2);


	public:
	singlyll();
	int printList();
	ListNode *getHead() { return head; }; /* Returns the value of the head pointer */
	void insertHead(int data);
	void insertEnd(int data);
	int insertAt(int index, int data);
	int insertSorted(); /* Insert element in a sorted fashion */
	int deleteHead();
	int deleteEnd();
	int deleteAt(int index);
	int deleteElement(int data);
	int printMiddle();
	void makeCycle(); /* Creates a cycle in the linked list */
	bool checkCycle(); /* Checks if there is a cycle in the linked list */
	void removeCycle(); /* Removes a cycle from the linked list */
	int detectIntersection(); /* Get the intersection point of of two linked list */
	int printReverse(); /* Prints the element of linked list in reverse order */
	void reverseUsingRecursion(); /* Reverse a linked list using recursion */
	void reverseIteratively(); /* Reverse a linke list iteratively */
	void reverseKNodes(const int &k); /* Reverse every k nodes of a linked list */
	int removeDuplicates(); /* Removes duplicate elements */
	int deleteAlternateNodes(); /* Delete alternate nodes of a linked list */
	int rotateKNodes(); /* Rotate linked list by K nodes */
	int mergeAtAlternate(); /* Merge a linked list into another list at alternate positions */
	int printNFromEnd(); /* Print nth node from the end */

	void mergeSortedList(ListNode *l1, ListNode *l2);
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

void singlyll::reverseUsingRecursion() {
	head = auxReverseUsingRecursion(head);
}

ListNode *singlyll::auxReverseUsingRecursion(ListNode *root){
	if(!root)
		return NULL;

	ListNode *nextNode = root->next;

	/* If the next pointer is NULL then we are at the last of the linked list. Make this last node the new root node */
	if(nextNode == NULL) {
		return root;
	}
	
	/* Reverse the linked list */
	root->next = NULL;
	ListNode *newHead = auxReverseUsingRecursion(nextNode); /* Get the new root of the linked list */
	nextNode->next = root;

	/* Resturn the new root of the linked list */
	return newHead;

}

void singlyll::reverseIteratively() {
	ListNode *prev =NULL, *nextNode = NULL;
	ListNode *root = head;

	if(!head){
		cout << "List is empty" << endl;
		return;
	}

	while(root) {
		nextNode = root->next; /* Save the pointer to next node */
		root->next = prev; /* Make the next pointer of the current node point to previous node */
		prev = root; /* The previous node for the next iteration is the current node */
		root = nextNode; /* Follow the above three steps for the next node */
	}
		
	head = prev;
}

void singlyll::reverseKNodes(const int &k) {
		head = auxReverseKNodesRecursively(head,k);
}

ListNode *singlyll::auxReverseKNodesRecursively(ListNode *root,const int &k) {
	ListNode *prev = NULL, *nextNode = NULL, *current = root;
	int count = 1;

	/* Revers the atmost k elements of the linked list */
	while(current && count <= k) {
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
		++count;
	}
	
	/* current now points to k+1th element. Start reversing the linked list from k+1th element onwards */
	if(current != NULL)
		root->next = auxReverseKNodesRecursively(current, k);

	return prev;
}

void singlyll::makeCycle() {
	ListNode * current = head;
	
	while(current->next != NULL) {
		current = current->next;
	}

	current->next = head->next->next->next->next;
}

bool singlyll::checkCycle(){
	ListNode *slowP = head, *fastP = head;

	while(fastP && fastP->next) {
		slowP = slowP->next;
		fastP = fastP->next->next;

		if(slowP == fastP)
			return true;		
	}

	return false;
}
	
void singlyll::removeCycle() {
	ListNode *slowP = head, *fastP = head;

	while(fastP && fastP->next) {
		slowP = slowP->next;
		fastP = fastP->next->next;

		if(slowP == fastP) {
			cout << "Removing cycle from the linked list" << endl;
			slowP = head;
	
			while(slowP->next != fastP->next) {
				slowP = slowP->next;
				fastP = fastP->next;
			}
			fastP->next = NULL;
			return;
		}
	}

	cout << "Cycle Doesn't exist" << endl;
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

int singlyll::printReverse() {
	if (head==NULL) {
		cout << "List is empty" << endl;
		return -1;
	}

	auxPrintReverse(head);
}

void singlyll::auxPrintReverse(ListNode *root) {
	if(root->next != NULL)
		auxPrintReverse(root->next);

	cout << root->data << endl;
}

void singlyll::mergeSortedList(ListNode *l1, ListNode *l2) {
	head = auxMergeSortedList(l1, l2);
}

ListNode *singlyll::auxMergeSortedList(ListNode *l1, ListNode *l2) {
	ListNode *head = NULL, *tail = NULL;
	
	cout << "Merging the linked lists" <<endl;
	/* If one of the list is empty return the other list. If both the lists are empty return NULL */
	if(l1 == NULL){
		cout << "l1 is NULL" << endl;
		return l2;
	}
	else if (l2 == NULL ){
		cout << "l2 is NULL" <<endl;
		return l1;
	}

	/* Initialize the head pointer of the new list */
	if(l1->data < l2->data) {
		cout << "head pointer points to l1" << endl;
		head = l1;
		tail = l1;
		l1 = l1->next;
		tail->next = NULL;
	}
	else {
		cout << "head pointer points to l2" << endl;
		head = l2;
		tail = l2;
		l2 = l2->next;
		tail->next = NULL;
	}

	/* Merge the sorted lists */
	while(l1 != NULL && l2 != NULL) {
		if(l1->data < l2->data) {
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
			tail->next = NULL;
		}
		else {
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
			tail->next = NULL;
		}
	}

	if(l1 == NULL)
		tail->next = l2;
	else
		tail->next = l1;

	/* Return the new head */
	return head;
}

int main() {
	/*singlyll list;

	for(int i =0; i<20; i++) {
		//list.insertHead(i);
		list.insertEnd(i);
	}*/

	//list.makeCycle();

	/*if(list.checkCycle())
		cout << "Cycle exists in the linked list" << endl;
	else
		cout << "Cycle doesn't exist in the linked list" << endl;*/

	//list.removeCycle();

	//list.reverseUsingRecursion();

	//list.reverseIteratively();

	//list.reverseKNodes(4);

	//list.printReverse();

	//list.printMiddle();
	//list.insertAt(56,16);
	
	singlyll list1,list2;

	for(int i=0;i<10;++(++i))
	{
		list1.insertEnd(i);
	}

	for(int i=1;i<10;++(++i)) {
		list2.insertEnd(i);
	}

	//list1.printList();
	//list2.printList();
	list1.mergeSortedList(list1.getHead(), list2.getHead());
	list1.printList();

	//list.printList();

	return 0;
}

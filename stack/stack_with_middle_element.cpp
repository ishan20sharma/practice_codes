#include<iostream>

using namespace std;

class ListNode {
	int data;
	ListNode *prev;
	ListNode *next;

public:
	ListNode(int value);
	int getData() const;
	ListNode *getPrev() const;
	ListNode *getNext() const;

friend class DLL;

};


ListNode::ListNode(int value):data(value),next(NULL),prev(NULL) {};

int ListNode::getData() const {
	return data;
}

class DLL {
	ListNode *head;
	ListNode *tail;
	ListNode *middle;
	int count;
public:
	DLL();
	~DLL();
	void pushFront(const int &value);
	void pushBack(const int &value);
	bool popFront(int &value);
	bool popBack(int &value);
	bool isEmpty();
	void printMiddle();
	void printList();

};

/* Default Constructor */
DLL::DLL():head(NULL), tail(NULL), middle(NULL), count(0) {
};

/* Default Destructor */
DLL::~DLL() {
	while(head) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}
	cout << "Linked-list Destructor Finished" << endl;
}

bool DLL::isEmpty() {
	return head == NULL;
}

void DLL::pushFront(const int &value) {
	ListNode *newNode = new ListNode(value);
	count++;

	if(isEmpty()) {
		head = tail = middle = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		if(count & 1) {
			cout << "Incementing middle element" << endl;
			middle = middle->prev;
		}
	}
}

void DLL::pushBack(const int &value) {
	ListNode *newNode = new ListNode(value);
	count ++;

	if(isEmpty()) {
		head = tail = middle =  newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		if(count & 1)
			middle = middle->next;
	}
}

bool DLL::popFront(int &value) {
	if(isEmpty()) {
		cout << "List Empty: Can't delete elements" << endl;
		return false;
	}
	else {
		count--;
		value = head->data;
		ListNode *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		if(!(count & 1))
			middle = middle->next;
		return true;
	}
}

bool DLL::popBack(int &value) {
	if(isEmpty()) {
		cout << "List Empty: Can't delete element" << endl;
		return false;
	}
	else {
		count--;
		value = tail->data;
		ListNode *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		if(!(count & 1))
			middle = middle->prev;
		return true;
	}
}

void DLL::printMiddle() {
	cout << "Middle element is: " << middle->data << endl;
}

void DLL::printList(){
	if(isEmpty()) {
		cout << "Empty List: Can't print" << endl;
		return;
	}
	else {
		cout << "Printing list elements" << endl;
		ListNode *current = head;
		while(current) {
			cout << current->data << endl;
			current = current->next;
		}
	}
}


class Stack {
	DLL list;

public:
	//Stack();
	//~Stack();
	void push(const int &value);
	bool pop(int &value);
	bool isEmpty();
	void printMiddle();
	void printStack();
};

/*Stack::~Stack(){
	delete list;
	cout << "Stack Destructor finished" << endl;
}*/

void Stack::push(const int &value) {
	list.pushFront(value);
}

bool Stack::pop(int &value) {
	list.popFront(value);
}

bool Stack::isEmpty() {
	return list.isEmpty();
}

void Stack::printStack() {
	list.printList();
}

void Stack::printMiddle() {
	list.printMiddle();
}

int main() {
	/*Stack st;
	
	for(int i=0; i<10; i++)
		st.push(i);

	st.printStack();

	st.printMiddle();*/

	DLL list;
	int b;

	for(int i=0; i<10; i++)
		list.pushBack(i);

	list.printList();
	list.popBack(b);
	list.popBack(b);
	list.printList();
	list.printMiddle();

	return 0;
}

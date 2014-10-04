#include<iostream>
#include<cstdlib>

using namespace std;

class Stack {
	int *store;
	int top; /* Points to the last inserted element index */
	int capacity; /* The size of the stack */
public:
	Stack(int cap);
	~Stack();
	bool push(const int &data);
	int pop();
	bool isEmpty();
	bool isFull();
	void printStack();
};

/* Constructor */
Stack::Stack(int cap) {
	capacity = cap;
	store = new int[capacity];
	top = -1;
}

/* Destructor */
Stack::~Stack() {
	delete[] store;
}

/* Push operation */
bool Stack::push(const int &data) {
	if(top < (capacity - 1)) {
		store[++top] = data;
		return true;
	}
	else {
		cout << "Stack Full" << endl;
		//return false;
		exit(0);
	}
}

/* Pop operation */
int Stack::pop() {
	if(top == -1) {
		cout << "Stack Empty" << endl;
		return -1;
	}
	else {
		return store[top--];
	}
}

/* Check whether the stack is full */
bool Stack::isFull() {
	return (top == capacity -1);
}

/* Check whether the stack is empty */
bool Stack::isEmpty() {
	return (top == -1);
}

/* Prints the contents of the stack */
void Stack::printStack() {
	for(int i=0; i<=top; i++)
		cout << store[i] << endl;
}

int main() {
	Stack st(10);

	for(int i=0; i<10; i++) {
		//cout << "stack top: " << st.top << endl;
	
		st.push(i);
	} 

	st.printStack();
	return 0;
}

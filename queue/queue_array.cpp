#include<iostream>

using namespace std;


class Queue {
	int *store; 
	int head; /* Starting index of the queue */
	int tail; /* Last index of the queue */
	int capacity; /* Size of the store array */
	int size; /* Number of elements in the queue */

public:
	Queue(int cap);
	~Queue();
	bool enqueue(const int &val);
	bool dequeue();
	bool isFull() const {return size==capacity;};
	bool isEmpty() const {return size==0;};
	int getSize() const {return size;};
	int getFirst() const {return store[head];};
	int getLast() const {return store[tail];};
	void printStore();
};

Queue::Queue(int cap) {
	capacity = cap;
	store = new int[capacity];
	size = 0;
	head = tail = -1;
}

Queue::~Queue() {
	delete[] store;
}

bool Queue::enqueue(const int &val){
	/* If the queue is full element can't be inserted */
	if(isFull())
		return false;
	
	/* Space avaialable: increment the tail index, insert the element and increment the size */
	tail = (tail+1)%capacity;
	store[tail] = val;
	++size;
	if(head == -1)
		++head;

	return true;
}

bool Queue::dequeue() {
	/* Can't delete element from an empty queue */
	if(isEmpty())
		return false;
	
	/* Queue not empty: return the first element, increment the head index, decrease the size */
	head = (head+1)%capacity;
	--size;
	return true;
}

void Queue::printStore() {
	cout << "Index of head is: " << head << endl;
	cout << "Value at head index is: " << store[head] <<endl;
	for(int i = head; i <= tail; i++) {
		cout << store[i] << endl;
	}
}

int main() {
	Queue q(20);
	for(int i=0,j=100;i<10;++j,++i) 
		q.enqueue(j);

	q.printStore();

	for(int i = 0; i<10;++i)
		q.dequeue();

	q.printStore();
	return 0;
}

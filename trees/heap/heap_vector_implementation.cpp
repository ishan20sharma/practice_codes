#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

template<typename T>
class Heap {
	vector<T> heap; /* Stores the heap elements */
	int left(const int &parent) const;
	int right(const int &parent) const; 
	int parent(const int &child) const;

	/* Functions for max-heap */
	void maxHeapifyUp(int child);
	void maxHeapifyDown(int parent);

	/* Functions for min-heap */
	void minHeapifyUp(const int&);
	void minHeapifyDown(const int&);
public:
	/* Functions for max-heap */
	void insertMax(const T &element); /* Inserts element in max-heap */
	T extractMax(); /* Returns and deletes the maximum element from the max-heap */
	T getMax();

	/* Functions for min-heap */
	void insertMin(const T &element); /* Inserts element in min-heap */
	T getMin();

	/* Common functions */
	void printHeap();
};

/* Returns the index of the left child */
template <typename T>
int Heap<T>::left(const int &parent) const {
	int l = (2*parent)+1;
	return  l < heap.size()? l: -1;
}

/* Returns the index of right child in the array */
template <typename T>
int Heap<T>::right(const int &parent) const {
	int r = (2*parent)+2;
	return r < heap.size()? r: -1;
}

/* Returns the index of the parent */
template <typename T>
int Heap<T>::parent(const int &child) const {
	return floor((child - 1)/2);
}

/* Floats the node upwards until it is greater than its children and is not the root node */
template <typename T>
void Heap<T>::maxHeapifyUp(int child) {
	/* If the node is greater than its parent then swap the node with the parent node  */
	while(child > 0 && heap.at(child) > heap.at(parent(child))) {
		T temp = heap.at(child);
		heap.at(child) = heap.at(parent(child));
		heap.at(parent(child)) = temp;
		child = parent(child);
	}
}

/* Floats the node downwards until it is greater than its children and  is not a leaf node */
template <typename T>
void Heap<T>::maxHeapifyDown(int parent) {
	int leftC = left(parent);
	int rightC = right(parent);

	/* Checks whether the node is a leaf node or not*/
	while(parent < heap.size() && (leftC != -1 || rightC != -1)) {
		leftC = left(parent);
		rightC = right(parent);
		int largest = parent;

		/* Identify the largest element from parent and left node */
		if(leftC != -1) {
			if(heap.at(leftC) > heap.at(largest)) {
				largest = leftC;
			}
		}

		/* Identify the largest element from current largest and right node */
		if(rightC != -1) {
			if(heap.at(rightC) > heap.at(largest)) {
				largest = rightC;
			}
		}

		/* If parent is not the largest element: swap parent with the current largest element */
		if(largest != parent) {
			T temp = heap.at(parent);
			heap.at(parent) = heap.at(largest);
			heap.at(largest) = temp;
			/* Change the index of parent to current largest element */
			parent = largest;

		}
		/* The present subtree is already a max-heap so terminate the procedure */
		else
			return;
	}
	/* Node is a leaf node */
	return;
}

/* Inserts an element into max-heap */
template <typename T>
void Heap<T>::insertMax(const T &element) {
	heap.push_back(element);
	maxHeapifyUp(heap.size() - 1);
}

/* Deletes and returns the maximum element from the max-heap */
template <typename T>
T Heap<T>::extractMax() {
	/* Swap the maximum element with the last leaf element */	
	T temp = heap.at(0);
	heap.front() = heap.back();
	heap.back() = temp;
	
	/* Delete the last element */
	heap.erase(heap.end() -1);

	/* Make sure max-heap property is maintained by the first element */
	maxHeapifyDown(0);
	
	/* Return the temp variable which stores the maximum element */
	return temp;
}

template <typename T>
T Heap<T>::getMax() {
	return heap.front();
}

template <typename T>
void Heap<T>::minHeapifyUp(const int &index) {

}

template <typename T>
void Heap<T>::minHeapifyDown(const int &index) {

}

template <typename T>
T Heap<T>::getMin() {
	return heap.at(0);
}

template <typename T>
void Heap<T>::insertMin(const T &element) {
	heap.push_back(element);
	MinHeapifyUp(heap.size() - 1);
}

template <typename T>
void Heap<T>::printHeap() {
	for(typename vector<T>::iterator it = heap.begin(); it != heap.end(); ++it)
		cout << *it << endl;
}

/* main() for testing max-heap */
int main() {
	Heap<int> maxheap;

	maxheap.insertMax(5);
       	maxheap.insertMax(8);
	maxheap.insertMax(16);
	maxheap.insertMax(7);
	maxheap.insertMax(2);
	maxheap.insertMax(3);
	maxheap.insertMax(11);
	maxheap.insertMax(15);
	maxheap.insertMax(18);

	cout << "Printing Max-Heap array" << endl ;
	maxheap.printHeap();

	maxheap.extractMax();
	cout << "deleted elements" << endl;

	maxheap.printHeap();
	cout << "Maximum element is: " << maxheap.getMax() << endl;

	return 0;
}

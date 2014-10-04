#ifndef STACK_H
#define STACK_H

#include<iostream>

/* Forward Refrences */
template <typename T>
class Stack;

template <typename T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & s);
 

template <typename T>
class Stack {
	T* data;
	int top; /* Top of the stack */
	int capacity; /* Capacity of the array */
	int increment; /* Each subsequent increment size */

public:
	Stack(int capacity=10, int increment=10);
	~Stack();
	void push(const T &value);
	bool pop(T &value);
	bool isEmpty() const;

};

template <typename T>
Stack<T>::Stack(int cap, int inc) : capacity(cap), increment(inc) {
	data = new T[capacity];
	top = -1;
}

template <typename T>
Stack<T>::~Stack() {
		delete[] data; /* Removes the dynamically allocated storage */
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return (top < 0);
}

template <typename T>
void Stack<T>::push(const T &value) {
	if(top < capacity -1)
		data[++top] = value;
	else {
		T *newData = new T[capacity + increment];
		for(int i = 0; i <= top; ++i)
			newData[i] = data[i];

		delete [] data;
		data = newData;
	}
}

template <typename T>
bool Stack<T>::pop(T &value) {
	if(isEmpty())
		return false;
	else {
		value = data[top--];
	}
	return true;
}

// Overload the stream insertion operator to print the list
template <typename T>
std::ostream & operator<< (std::ostream & os, const Stack<T> & stack) {
   os << '{';
   for (int i = stack.tos; i >= 0; --i) {
      os << stack.data[i];
      if (i > 0) os << ',';
   }
   os << '}';
}
#endif

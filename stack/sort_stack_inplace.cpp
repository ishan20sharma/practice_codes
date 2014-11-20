#include<iostream>
#include<stack>

using namespace std;

void auxSortStack(int sTop, stack<int> &st) {
	if(st.empty()) {
		st.push(sTop);
		return;
	}

	int nTop = st.top();

	/* Swap the current stack top with the new top element */
	if(nTop > sTop) {
		int temp = nTop;
		nTop = sTop;
		sTop = temp;
	}

	st.pop();

	/* The new top element becomes the top for the next stack in recursion */
	auxSortStack(nTop, st);

	st.push(sTop); 
}

void sortStack(stack<int> &st) {
	for(int i = 0; i < st.size() ; ++i) {
		int sTop = st.top();
		st.pop();
		auxSortStack(sTop, st);
	}
}

void printStack(stack<int> &st) {
	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}

int main() {
	stack<int> st;
	
	st.push(10);
	st.push(13);
	st.push(41);
	st.push(72);
	st.push(15);

	sortStack(st);

	printStack(st);

	return 0;
}

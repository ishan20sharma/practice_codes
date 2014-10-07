#include<iostream>
#include<stack>

using namespace std;

void reverseStack(stack<int> &st);
void printStack(stack<int> &st);

int main() {
	stack<int> st;

	for(int i=0;i<10;i++)	
		st.push(i);

	reverseStack(st);
	printStack(st);
	return 0;
}

void reverseStack(stack<int> &st) {
	int temp = -1;
	if(!st.empty()) {
		temp = st.top();
		st.pop();
		if(!st.empty())
			reverseStack(st);
	}
	//if(temp!= -1)
		st.push(temp);
}

void printStack(stack<int> &st) {
	cout << "Printing Stack" << endl;
	while(!st.empty()) {
		cout<< st.top() << endl;
		st.pop();
	}
}

#include<iostream>
#include<stack>

using namespace std;

void printNge(int *arr);

int main() {
	int arr[] = {1,4,2,6,3,8,7,2,6};

	printNge(arr);

	return 0;
}

void printNge(int *arr) {
	stack<int> st;

	st.push(arr[0]);
	
	for(int i=1; i<9;i++) {
		while(!st.empty() && (st.top() < arr[i])) {
			cout << "Element is:" << st.top() << "  NGE is:" << arr[i] << endl;
			//cout << "Removing element: " << st.top() << endl;
			st.pop();
		}
		cout << "Pushing element: " << arr[i] << endl;
		st.push(arr[i]);
	}
	while(!st.empty()) {
		cout << "Element is:" << st.top() << "  NGE is:" << -1 << endl;
		st.pop();
	}
	
}

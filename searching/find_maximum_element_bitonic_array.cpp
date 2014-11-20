#include<iostream>

using namespace std;

int locateMaximum(int bitonic[], const int &left, const int &right) {

	if(left <= right) {
		if(left == right) 
			return left;

		int mid = (left+right)/2;

		if(bitonic[mid-1] < bitonic[mid] && bitonic[mid+1] < bitonic[mid])
			return mid;

		else if(bitonic[mid-1] < bitonic[mid] && bitonic[mid+1] > bitonic[mid]) {
			return locateMaximum(bitonic, mid+1, right);
		}

		else if(bitonic[mid-1] >  bitonic[mid] && bitonic[mid+1] < bitonic[mid]) {
			return locateMaximum(bitonic, mid-1, left);
		}

		return -1;
	}
}

int main() {
	int bitonic[] = {1,3,5,7,9,10,15,8,6,4,2};

        int index = locateMaximum(bitonic,0, sizeof(bitonic)/sizeof(bitonic[0])-1);

        cout << "The maximum element is at index: " << index << endl;


	return 0;
}

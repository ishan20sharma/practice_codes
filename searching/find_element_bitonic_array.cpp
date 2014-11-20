/*
First, a bitonic array for this question is defined as one such that for some index K in an array of length N where 0 < K < N - 1 and 0 to K is a monotonically increasing sequence of integers, and K to N - 1 is a monotonically decreasing sequence of integers.

Example: [1, 3, 4, 6, 9, 14, 11, 7, 2, -4, -9]. It monotonically increases from 1 to 14, then decreases from 14 to -9.
*/

#include<iostream>

using namespace std;

int locateElement(int bitonic[], const int &left, const int &right, const int &element) {
	int mid = (left+right)/2;

	if(bitonic[mid] == element)
		return mid;

	if(bitonic[mid-1] < bitonic[mid] && bitonic[mid]+1 < bitonic[mid]) {
		if(element <= bitonic[mid-1]) {
			return locateElement(bitonic, left, mid-1, element);
		}
		else if(element >= bitonic[mid+1]) {
			return locateElement(bitonic, mid+1, right, element);
		}
	}

	/* Element belongs to an increasing sequence on the right */
	else if(element > bitonic[mid] && bitonic[mid + 1] > bitonic[mid]) {
		return locateElement(bitonic, mid+1, right, element);
	}

	/* Element belongs to an increasing sequenc on the left */
	else if(element > bitonic[mid] && bitonic[mid - 1] > bitonic[mid]) {
		return locateElement(bitonic, left, mid - 1, element);
	}

	/* Element belongs to a decreasing sequence on the right */
	else if(element < bitonic[mid] && bitonic[mid+1] < bitonic[mid]) {
		return locateElement(bitonic, mid+1, right, element);
	}

	/* Element belongs to a decreasing sequence on the left */
	else if(element < bitonic[mid] && bitonic[mid-1] < bitonic[mid]) {
		return locateElement(bitonic, left, mid-1, element);
	}

	return -1;
}
	

int main() {
	int bitonic[] = {1,3,5,7,10,8,6,4,2};
	int element = 10;

	int index = locateElement(bitonic,0, sizeof(bitonic)/sizeof(bitonic[0])-1, element);

	cout << "The element " << element << " is at index: " << index << endl;

	return 0;
}

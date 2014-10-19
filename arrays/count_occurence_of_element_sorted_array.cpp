#include<iostream>

#define FIRST true
#define LAST false

using namespace std;

/* Locate the first or last occurence of a value in a sorted array depending on value of 'first' variable */
int firstLastBinarySearch(int *arr, const int &size, const int &value,const bool &first ) {
	int low = 0;
	int high = size-1;
	int result = -1;

	while(low <= high) {
		int mid = (low+high)/2;
		if(value == arr[mid]){
			result = mid;
			/* Check whether we are looking for first occurence of the element */
			if(first) {
				high = mid - 1;
			}
			/* We are looking for the last occurence of the element */
			else {
				low = mid + 1;
			}
		}
		else if(value < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

int main() {

	int arr[] = {2,3,3,3,3,5,5,6,7,8};

	/* Locate the first occurence of the element */
	int first = firstLastBinarySearch(arr,10,3,FIRST);
	
	/* Locate the last occurence of the element */
	int last = firstLastBinarySearch(arr,10,3,LAST);

	cout << "The number of occurence of element 3 is: " << last - first + 1 << endl;

	return 0;
}

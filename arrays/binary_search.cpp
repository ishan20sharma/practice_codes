#include<iostream>

using namespace std;

int binarySearch(int *arr,const int &size,const int &value);

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	
	binarySearch(arr,14,2);

	return 0;
}

int binarySearch(int *arr, const int &size, const int &value) {
	int low = 0;
	int high = size-1;

	while(low <= high) {
		int mid = (low+high)/2;

		if(value == arr[mid]) {
			cout << "Found " << value << " at index: " << mid << endl;
			return mid;
		}
		else if(value < arr[mid]){
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return -1;
}

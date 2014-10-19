#include<iostream>

using namespace std;


int firstBinarySearch(int *arr,const int &size,const int &value);
int lastBinarySearch(int *arr,const int &size,const int &value);

/* Identifies the first occurence of the element */
int firstBinarySearch(int *arr, const int &size, const int &value) {
	int low = 0;
	int high = size-1;
	int result = -1;

	while(low <= high) {
		int mid = (low+high)/2;

		if(value == arr[mid]) {
			result = mid;
			high = mid - 1;
		}	
		else if(value < arr[mid]) {
			high = mid -1;
		}
		else {
			low = mid+1;
		}
	}
	return result;
}

int lastBinarySearch(int *arr, const int &size, const int &value) {
	int low = 0;
	int high = size-1;
	int result = -1;

	while(low <= high) {
		int mid = (low+high)/2;
		if(value == arr[mid]){
			result = mid;
			low = mid +1;
		}
		else if(value < arr[mid]) {
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}

	return result;
}	


int main() {
	int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
	
	cout << "First occurence of 1 is at index: " << firstBinarySearch(arr, 13, 1) << endl;

	cout << "Last occurence of 1 is at index: " << lastBinarySearch(arr, 13, 1) << endl;

	return 0;
}

/*
Given an array arr[0 ... n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void longestBitonicSubsequence(int sequence[], int length) {
	vector<int> lis(length, 1); /* Stores the value for longest increasing subsequence */
	vector<int> lds(length, 1); /* Stores the value for longest decreasing subsequence */

	cout << "Computing the longest increasing subsequence array"  << endl;
	for(int i = 1; i < length; ++i) {
		for(int j = 0; j < i; ++j) {
			if((sequence[j] < sequence[i]) && (lis[j] + 1 > lis[i])) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	cout << "Computing the longest dcreasing subsequence array" << endl;
	for(int i = length - 2; i >= 0; --i) {
		for(int j = length - 1; j > i; --j) {
			if((sequence[j] < sequence[i]) && (lds[j] + 1 > lds[i])) {
				lds[i] = lds[j] + 1;
			}
		}
	}
	
	cout << "Calculating the maximum value for bitonic subsequence" << endl;
	int max = INT_MIN;
	for(int i = 0; i < length; ++i) {
		if(lis[i] + lds[i] - 1 > max) {
			max = lis[i] + lds[i] - 1;
		}
	}

	cout << "The length of longest bitonic subsequence is: " << max << endl;
	
}

int main() {
	int sequence[] = {1, 11, 2, 10, 4, 5, 2, 1};

	longestBitonicSubsequence(sequence, sizeof(sequence)/sizeof(sequence[0]));

	return 0;
}

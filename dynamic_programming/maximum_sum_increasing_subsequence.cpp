/*
  Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are
  sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10},
  then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void maximumSumIncreasingSubsequence(int sequence[], int length) {
	vector<int> lis;
	vector<int> msis;
	int maxSum = 0;
	int maxSumIndex = -1;
	
	lis.push_back(1);
	msis.push_back(sequence[0]);

	for(int i =1 ; i < length; ++i) {
		int step = -1;
		int longestSubsequence = 0;
		int prevLongestSubsequence = longestSubsequence;
		for(int j = 0; j < i; ++j) {
			if(sequence[j] < sequence[i]) {
				prevLongestSubsequence = longestSubsequence;
				longestSubsequence = max(longestSubsequence, lis[j]);

				if(longestSubsequence != prevLongestSubsequence) {
					step = j;	
				}
			}
		}

		lis.push_back(1 + longestSubsequence);
		
		if(step != -1) {
			msis.push_back(sequence[i] + msis[step]);
		}

		if(msis[i] >= maxSum) {
			maxSum = msis[i];
			maxSumIndex = i;
		}
	}

	cout << "The maximum sum increasing subsequence is: " << maxSum << endl;
}

int main() {
	int sequence[] = {3, 4, 5, 10}; 

	/* if sequence[] = {1, 101, 2, 3, 100, 4, 5};  Answer should be 106 (1 + 2 + 3 + 100)
	   if sequence[] = {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)
	   if sequence[] = {10, 5, 4, 3}, then output should be 10 */

	maximumSumIncreasingSubsequence(sequence, sizeof(sequence)/sizeof(sequence[0]));
	
	return 0;
}


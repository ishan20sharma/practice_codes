#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void longestIncreasingSubsequence(int sequence[], int length) {
	vector<int> lis;
	int lisValue = 0; /* The length of LIS */
	int lisIndex = -1; /* The index where LIS ends */

	lis.push_back(1); /* The longest increasing sequence starts with sequenc[0] */

	for(int i = 1; i < length; ++i) {
		int lSubSequence = 0;
		for(int j = 0; j < i; ++j) {
			if( sequence[j] < sequence[i]) {
				lSubSequence = max(lSubSequence, lis[j]);
			}
		}
		lis.push_back(1 + lSubSequence);

		/* Store the value of LIS found till i and store the index i where LIS ends */
		if(lis[i] >= lisValue) {
			lisValue = lis[i];
			lisIndex = i;
		}
	}

	cout << "The lenght of the LIS is : " << lisValue << endl;
}

int main() {
	int sequence[] = {9, 11, 2, 13, 7, 15}; /* Answer should be 4 */
	
	longestIncreasingSubsequence(sequence, sizeof(sequence)/sizeof(sequence[0]));
	
	return 0;
}

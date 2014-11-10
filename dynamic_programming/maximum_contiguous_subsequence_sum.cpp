#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void mcss(int sequence[], int length) {
	vector<int> maxSum;
	
	maxSum.push_back(sequence[0]);

	for(int i = 1; i < length; ++i) {
		if(maxSum[i-1] + sequence[i] > sequence[i]) {
			maxSum.push_back(maxSum[i-1] + sequence[i]);
		}
		else {
			maxSum.push_back(sequence[i]);
		}
	}

	int max = INT_MIN;
	for(int i = 0; i < length; ++i) {
		//cout << maxSum[i] << endl;
		if(maxSum[i] > max)		
			max = maxSum[i];
	}

	cout << "The maximum contiguous subsequence sum is : " << max << endl;
}

int main() {
	int sequence[] = {2, -4, 1, 2};

	mcss(sequence, sizeof(sequence)/sizeof(sequence[0]));
	return 0;
}

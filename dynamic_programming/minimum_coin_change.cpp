/*
Given a set of coin denominations (V1 = 1, V2, V3, ..., Vn) and an amount of money (C). Make change for the given amount of money using a minimum number of coins.
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

void coinChange(int coinValue[], int nCoins, int amount) {

	vector<int> mChange; /* Stores the minimum change for an amount i */
	mChange.push_back(0);

	/* Compute the minimum change value for all i upto amount */
	/*for(int i = 1; i <= amount; ++i) {
		int minVal = INT_MAX;
		for(int j = 0; (i - coinValue[j] >= 0 ) && j < nCoins; ++j) {
			minVal = min(minVal, mChange[ i - coinValue[j]]);
		}
		mChange.push_back(1 + minVal);
	}*/

	for(int i = 1; i <= amount; ++i) {
		mChange.push_back(INT_MAX);
		for(int j = 0; (i - coinValue[j] >= 0) && j < nCoins; ++j) {
			if(mChange[i - coinValue[j]] + 1 < mChange[i]) {
				mChange[i] = mChange[i - coinValue[j]] + 1;
			}
		}
	}

	cout << "The minimum number of change required for value " << amount << " is: " << mChange[amount] << endl;
}

int main() {
	int coinValue[] = {1, 5, 10, 25};
	int amount = 67;
	/* amount 40, mChange[40] = 3
	   amount 67, mChange[67] = 6 
	   amount 40, mChange[40] = 3	*/	

	coinChange(coinValue, sizeof(coinValue)/ sizeof(coinValue[0]), amount);

	return 0;
}

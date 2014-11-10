#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

void rodCut(int price[], int logSize) {

	vector<int> bPrice; /* Stores the best price for a log of given size */

	bPrice.push_back(0);

	/*for(int i = 1; i <= logSize; i++) {
		int maxVal = INT_MIN;

		for(int j = 0; j < i; j++) {
			maxVal = max(maxVal, price[j] + bPrice[i - j - 1] );
		}
		bPrice.push_back(maxVal);
	} */

	for(int i = 1; i <= logSize; ++i) {
		bPrice.push_back(INT_MIN);
		for(int j = 0; j < i; ++j) {
			if(bPrice[i] < price[j] + bPrice[i - j - 1]) {
				bPrice[i] = price[j] + bPrice[i - j - 1];
			}
		}
	}

	cout << "The maximum price we can get for log of size " << logSize << " is : " << bPrice[logSize] << endl;
}

int main() {

	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int logSize = sizeof(price)/sizeof(price[0]);

	rodCut(price, logSize);

	return 0;
}

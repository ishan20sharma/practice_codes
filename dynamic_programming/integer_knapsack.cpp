#include<iostream>
#include<vector>

using namespace std;

void integerKnapsack(int weight[], int value[], int length, int capacity ) {
	vector<int> maxValue(capacity + 1, 0); /* capacity+1 because we are storing the value for weight 0 also */

	/* cout << "Calculating the maximum value for i = 1 to capacity" << endl */
	for(int i = 1; i <= capacity; ++i) {
		/* cout << "Calculating whether an item from weight[] with value from value[] can be inserted into the knapsack" << endl;*/
		for(int j = 0; j < length; ++j) {
			/* The weight of the item should not be greater than the knapsack's capacity */
			if(i - weight[j] > 0) {
				/* cout << "Identifying the item which maximises the value of the knapsack" << endl; */
				if(value[j] + maxValue[i - weight[j]] > maxValue[i]) {
					maxValue[i] = value[j] + maxValue[i - weight[j]];
				}	
			}
		}
		/* If there is no suitable item to insert in the knapsack or if the item doesn't increase the value of the knapsack then use the maxValue for the current capacity -1  */
		if(maxValue[i] <= maxValue[i - 1]) {
			maxValue[i] == maxValue[i-1];
		}
	}

	cout << "The maximum value for capacity " << capacity << " is: " << maxValue[capacity] << endl;
}

int main() {
	int weight[] = {5,4,6,3};
        int value[] = {10,40,30,50};
        int capacity = 10;	

	/* Test Case 1
	   int weight[] = {2,3,4};
       	   int value[] = {3,7,1};
           int capacity = 4;
           Answer = 7 (3)

	   Test Case 2
	   int weight[] = {5,4,6,3};
	   int value[] = {10,40,30,50};
           int capacity = 10;
           Answer = 150
	*/

	integerKnapsack(weight, value, sizeof(weight)/sizeof(weight[0]), capacity);

	return 0;
}

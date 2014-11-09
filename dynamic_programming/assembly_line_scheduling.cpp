#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* mCount = number of machines in an assembly line
** int **pTime = pTime[i][j] where i ==2 and j == mCount. It stores the processing time on line i for node j
** entry[0] == entry time on f1... entry[1] == entry time on f2 
** exit[0] == exit time from f1... exit[1] == exit time from f2
** int **transfer = transfer[i][j] where i ==2 and j == mCount. It stores the transfer time from station j on line i to station j+1 on line i-1 or i+1 
**/

void fastestWay(int **pTime, int **transfer,int mCount, int entry[2], int exit[2]) {
	vector<int> f1; /* Fastest time through the stations on line 1 */
	vector<int> f2; /* Fastest time through the stations on line 2 */

	int fTime; /* (Answer) Fastest time through both the lines */

	//cout << "Initializing f1[0] and f2[0]" << endl;
	f1.push_back(pTime[0][0] + entry[0]);
	f2.push_back(pTime[1][0] + entry[1]);

	//cout << "Initializing f1[1...mCount-1] and f2[1...mCount-1]"<< endl;
	for(int j = 1; j < mCount; ++j) {
		//cout << "value of j is: " << j << endl;

		/* Filling up f1 array for line 1 */
		if(f1[j-1] + pTime[0][j] <= f2[j-1] + pTime[0][j] + transfer[1][j]) {
			f1.push_back(f1[j-1] + pTime[0][j]);
		}
		else {
			f1.push_back(f2[j-1] + pTime[1][j] + transfer[1][j]);
		}

		/* Filling up f2 array for line 2 */
		if(f2[j-1] + pTime[1][j] <= f1[j-1] + pTime[1][j] + transfer[0][j]) {
			f2.push_back(f2[j-1] + pTime[1][j]);
		}
		else {
			f2.push_back(f1[j-1] + pTime[1][j] + transfer[0][j]);
		}
	}

	cout << "Calculating the fastest time" << endl;
	if(f1[mCount-1] + exit[0] <= f2[mCount-1] + exit[1]) {
		fTime = f1[mCount-1] + exit[0];
	}
	else {
		fTime = f2[mCount-1] + exit[1];
	}
	
	cout << "The fastest time is: " << fTime << endl;
}


/* mCount = number of machines in an assembly line
** int **pTime = pTime[i][j] where i ==2 and j == mCount. It stores the processing time on line i for node j
** entry[0] == entry time on f1... entry[1] == entry time on f2
** exit[0] == exit time from f1... exit[1] == exit time from f2
** int **transfer = transfer[i][j] where i ==2 and j == mCount. It stores the transfer time from station j on line i to station j+1 on line i-1 or i+1
**/
int main() {
	int mCount = 4;
	int entry[2];
	int exit[2];
	int **pTime;
	int **transfer;
	
	pTime = new int *[2];
	transfer = new int *[2];

	cout << "Creating the pTime and transfer matrix" << endl;
	for(int i = 0; i < 2; ++i) {
		pTime[i] = new int[mCount];
		transfer[i] = new int[mCount];
	}

	cout << "Initializing the pTime matrix" << endl;
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < mCount; ++j) {
			cin >> pTime[i][j];
			/* Input: 4 5 3 2 
				  2 10 1 4 */
		}
        }
 	
	cout << "Initializing the transfer matrix" << endl;
	for(int i = 0; i < 2; ++i) {
                for(int j = 0; j < mCount; ++j) {
                        cin >> transfer[i][j];
                        /* Input: 0 7 4 5 
				  0 9 2 8  */
                }
        }

	cout << "Initializing the entry array" << endl;
	for(int i = 0 ; i < 2; ++i) {
		cin >> entry[i];
		/* Input: 10 12 */
	}

	cout << "Initializing the exit array" << endl;
	for(int i = 0 ; i < 2; ++i) {
                cin >> exit[i];
		/* Input: 18 7 */
        }

	cout << "Calling the fastestWay() function" << endl;
	fastestWay(pTime, transfer, mCount, entry, exit);
	
	return 0;
}

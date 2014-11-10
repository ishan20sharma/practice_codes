/*
LCS for input Sequences ABCDGH and AEDFHR is ADH of length 3.
LCS for input Sequences AGGTAB and GXTXAYB is GTAB of length 4.
*/

#include<iostream>
#include<algorithm>

using namespace std;

void lcs(const string &X, const string &Y) {
	int **LCS;
	
	LCS = new int *[X.length() + 1];
	
	for(int i = 0; i<= X.length(); ++i) {
		LCS[i] = new int[Y.length() + 1];	
	}

	for(int i = 0; i <= X.length(); ++i) {
		for(int j = 0; j <= Y.length(); ++j) {
			/* Initialize the 0th row and column to 0 */
			if(i == 0 || j == 0) {
				LCS[i][j] = 0;
			}
			else if (X[i-1] == Y[j-1]) {
				LCS[i][j] = 1 + LCS[i-1][j-1];
			}
			else {
				LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
			}

			
		}
	}

	cout << "The length of the longest common subsequence is: " << LCS[X.length()][Y.length()] << endl;
}

int main() {
	string X = "ABCDGH";
	string Y = "AEDFHR";

	lcs(X,Y);
	

	return 0;
}

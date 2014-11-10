/*
Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: 30000 
  There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

  Input: p[] = {10, 20, 30}  
  Output: 6000  
  There are only two matrices of dimensions 10x20 and 20x30. So there 
  is only one way to multiply the matrices, cost of which is 10*20*30

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int min(int a, int b) {
	return a < b ? a: b;
}

void matrixChain(int mChain[], int length) {
	int tMatrices = length -1;
	int **mMultiplications; /* Minimum number of multiplications required between two matrices i and j */
	
	 /* For simplicity of the program, one extra row and one extra column are allocated in m[][].  0th row and 0th column of m[][] are not used */
	mMultiplications = new int *[length];
	for(int i = 0; i < length; ++i) {
		mMultiplications[i] = new int[length];
	}
	
	//cout << "Initializing mMultiplications[i][j] = -1" << endl;
	/* Initialize the matrix with -1 */
	/*for(int i = 0; i < tMatrices; ++i) {
		for(int j = 0; j <tMatrices; ++j) {
			mMultiplications[i][j] = -1;
		}
	}*/

	/* Ideally the following initialization function should be used 
	for(int i = 0; i < tMatrices; ++i) {
		for(int j = 0; j < tMatrices; ++j) {
			if (i == j)
				mMultiplications[i][j] = 0;
			else
				mMultiplications[i][j] = -1;
		}
	} */
	
	/* Matrices will not be multiplied by themselves */
	cout << "Initializing mMultiplications[i][j] = 0 iff i == j" << endl;
	for(int i = 0; i < length; ++i) {
                for(int j = 0; j < length; ++j) {
                        if (i == j)
                                mMultiplications[i][j] = 0;
                }
        } 

	for(int l = 2; l <= length; ++l) {
		for (int i = 1; i <= length - l + 1; ++i) {
			
		}
	}

	/*for(int i = 1; i < tMatrices-1; ++i) {
		for(int j = i+1; j <= tMatrices-1; ++j) {
			int minMul = INT_MAX;
			for(int k = i; k < j; ++k) {
				minMul = min(minMul, mMultiplications[i][k] + mMultiplications[k+1][j] + mChain[i-1]*mChain[k]*mChain[j]);
			}
			mMultiplications[i][j] = minMul;
		}

	}*/
	cout << "Minimum number of multiplications required for multiplying " << tMatrices - 1 << " matrices together is: " << mMultiplications[1][tMatrices-1] << endl;

}

int main() {
	int mChain[] = {10, 20, 30, 40, 30};	

	matrixChain(mChain, sizeof(mChain)/sizeof(mChain[0]));

	return 0;
}

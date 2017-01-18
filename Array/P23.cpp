#include <iostream>
using namespace std;

#define MAX 101

int r,c;
int a[MAX][MAX];

/**
 * Rotate a 2D matrix clockwise
 * 
 * Approach1: take transpose of the matrix and keep swapping columns from left and right.
 * 
 * Approach2:
 *   Let the matrix is: [1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,16]
 *   Imaging rotating it in layers, th eouter layer consists of first and last row and first and last coloumns.
 *   Procedure then is 
 * 		replace 1 with 13, 13 with 16, 16 with 4 and 4 with 1.
 * 		Replace 5 with 14, 14 with 12, 12 with 3 and 3 with 5 and so on.. 
 * 		Do this till you complete all the elements in this layer. 
 * 
 * Approach3:
 * 	 Recursively divide the matrix into four equal sized subarrays and rotate them.
 * 	 Let these arrays be A0, A1, A2,A3. Make a copy of A0 as C0, and write A1 to A0, A2 to A1, A3 to A2, A3 to C0.
 * 
 **/


// Approach 2
void rotateMatrix() {
	
	int i,j;
	
	for ( i=0; i<r/2; i++ ) {
		for ( j=i; j< r-i-1; j++ ) {
			int temp = a[i][j];
			
			a[i][j] = a[r-j-1][i];
			a[r-j-1][i] = a[r-i-1][r-j-1];
			a[r-i-1][r-j-1] = a[j][r-i-1];
			a[j][r-i-1] = temp;
		}
	}
	
}


// approach 3
/*void rotateMatrixRecursive(int rStart, int rEnd, int cStart, int cEnd ) {
	
	if ( rStart == rEnd && cStart == cEnd )
		return;
	
	int rMid = (rStart + rEnd)/2;
	
	int cMid = (cStart + cEnd)/2;
	
	int cnt = rEnd - rStart + 1;
	
	//create copies and then recursively rotate

	if ( cnt %2 == 0 ) {
		rotateMatrixRecursive(rStart, rMid, cStart, cMid);
		rotateMatrixRecursive(rMid, rEnd, cStart, cMid);
		rotateMatrixRecursive(rMid, rEnd, cMid, cEnd);
		rotateMatrixRecursive(rStart, rMid, cMid, cEnd);
	}
	else {
		rotateMatrixRecursive(rStart, rMid-1, cStart, cMid-1);
		rotateMatrixRecursive(rMid+1, rEnd, cStart, cMid-1);
		rotateMatrixRecursive(rMid+1, rEnd, cMid+1, cEnd);
		rotateMatrixRecursive(rStart, rMid-1, cMid+1, cEnd);
	}
	
	int re= rMid, ce = cMid;
	
	if ( cnt %2 !=0 ) {
		re = rMid-1;
		ce - cMid-1
	}
	
	
}*/

int main() {
	// your code goes here
	
	cin>>r>>c;
	
	int i,j;
	
	for ( i=0; i<r; i++ ) {
		for ( j=0; j<c; j++ )
			cin>>a[i][j];
	}
	
	// approach1 call
	rotateMatrix();
	
	// approach 2 call
//	rotateMatrixRecursive(0,0,r-1,c-1);
	
	cout << "The rotated matrix is : \n" ;
	
	for ( i=0; i<r; i++ ) {
		for ( j=0; j<c; j++ )
			cout << a[i][j] <<" " ;
			
		cout << endl;
	}
	
	return 0;
}
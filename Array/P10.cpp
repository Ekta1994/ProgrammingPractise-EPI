/**
 * Find maximum product of all elements in the array except one
 * Approach1: Use brute force, two loops O(n^2)
 * 
 * Approach2: Use an array to store product of pprefix and then do division for every element
 * The above approach has n multiplications and divisions
 * 
 * Approach3: use two array left amd right to store product of prefix and suffix for all i
 * 
 * Approach4: Coded below
 * Please note that 0 is included in positive numbers in this approach
 **/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	int i,a[n+1];
	
	for ( i=0; i<n; i++ ) {
		cin>>a[i];
	}
	
	int cntPos=0, cntNeg=0, largestNegIdx = -1, smallestNegIdx = -1, smallestPosIdx=-1;
	
	for ( i=0; i<n; i++ ) {
		if ( a[i] < 0 ) {
			cntNeg++;
			
			if ( smallestNegIdx == -1 || a[smallestNegIdx] < a[i] ) {
				smallestNegIdx = i;
			}
			
			if ( largestNegIdx == -1 || a[largestNegIdx] > a[i] ) {
				largestNegIdx = i;
			}
		}
		else {
			cntPos++;
			
			if ( smallestPosIdx == -1 || a[smallestPosIdx] > a[i] )
				smallestPosIdx = i;
		}
	}
	
	/**
	 * Case1: all elements in the array are +ve
	 * 		Sol: product of all except the smallest positive
	 * 
	 * Case2 : if all elements are -ve
	 * 		if count of -ve entries is odd
	 * 			product of all except the negative number with the smallest absolute value
	 *		else if count is even
	 * 			product of all except the largest absolute value - always negative answer
	 *
	 * 
	 * Case3: if both -ve and +ve are there
	 * 		if count of negative is even
	 * 			product of all except the smallest positive
	 * 		if count of negative is odd
	 * 			product of all except the negative number with the smallest absolute value
	 ***/
	 
	 int ans = 1;
	 
	 if ( cntNeg == 0 ) {
	 	// case1
	 	
	 	for ( i=0; i<n; i++ ) {
	 		if ( i!= smallestPosIdx ) 
	 			ans *= a[i];
	 	}
	 	
	 }
	 else if ( cntPos == 0 ) {
	 	// case 2
	 	
	 	if ( cntNeg %2 != 0 ) {
	 		for ( i=0; i<n; i++ ) {
		 		if ( i!= smallestNegIdx ) 
		 			ans *= a[i];
		 	}
	 	}
	 	else {
	 		for ( i=0; i<n; i++ ) {
		 		if ( i!= largestNegIdx ) 
		 			ans *= a[i];
		 	}
	 	}
	 	
	 }
	 else {
	 	// case 3
	 	
	 	if ( cntNeg %2 == 0 ) {
		 	for ( i=0; i<n; i++ ) {
		 		if ( i!= smallestPosIdx ) 
		 			ans *= a[i];
		 	}
		 }
		 else if ( cntNeg %2 != 0 ) {
		 	for ( i=0; i<n; i++ ) {
		 		if ( i!= smallestNegIdx ) 
		 			ans *= a[i];
		 	}
		 }
	 }
	 
	 cout << "Maximum product is : " << ans << endl;
	
	return 0;
}